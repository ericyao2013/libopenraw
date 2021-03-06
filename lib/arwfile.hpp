/* -*- Mode: C++; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * libopenraw - arwfile.hpp
 *
 * Copyright (C) 2006-2020 Hubert Figuière
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <libopenraw/cameraids.h>
#include <libopenraw/consts.h>

#include "rawfile.hpp"
#include "io/stream.hpp"
#include "ifddir.hpp"
#include "ifdfile.hpp"
#include "tiffepfile.hpp"

namespace OpenRaw {

class RawData;

namespace Internals {

class ArwFile
    : public TiffEpFile
{
    template<typename T>
    friend void audit_coefficients();

public:
    static RawFile *factory(const IO::Stream::Ptr & s);
    ArwFile(const IO::Stream::Ptr & s);
    virtual ~ArwFile();

    ArwFile(const ArwFile&) = delete;
    ArwFile & operator=(const ArwFile&) = delete;

protected:
    virtual IfdDir::Ref  _locateCfaIfd() override;

    virtual ::or_error _getRawData(RawData & data, uint32_t options) override;
    virtual bool vendorCameraIdLocation(Internals::IfdDir::Ref& ifd, uint16_t& index, const ModelIdMap*& model_map) override;

private:
    // first version of ARW. Different from the rest.
    bool isA100()
        {
            return typeId() == OR_MAKE_FILE_TYPEID(OR_TYPEID_VENDOR_SONY,
                                                   OR_TYPEID_SONY_A100);
        }

    static const IfdFile::camera_ids_t s_def[];
};

}
}
