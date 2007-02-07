/*
 * libopenraw - dngfile.cpp
 *
 * Copyright (C) 2006-2007 Hubert Figuiere
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#include <libopenraw/libopenraw.h>
#include <libopenraw++/thumbnail.h>

#include "debug.h"
#include "io/file.h"
#include "ifdfilecontainer.h"
#include "ifd.h"
#include "dngfile.h"

using namespace Debug;

namespace OpenRaw {


	namespace Internals {

		RawFile *DNGFile::factory(const char* _filename)
		{
			return new DNGFile(_filename);
		}


		DNGFile::DNGFile(const char* _filename)
			: IFDFile(_filename, OR_RAWFILE_TYPE_DNG)
		{

		}

		DNGFile::~DNGFile()
		{
		}

		::or_error DNGFile::_getRawData(RawData & data)
		{
			::or_error ret = OR_ERROR_NONE;
			IFDDir::Ref dir = m_container->setDirectory(0);

			Trace(DEBUG1) << "_getRawData()\n";

			std::vector<IFDDir::Ref> subdirs;
			if (!dir->getSubIFDs(subdirs)) {
				// error
				return OR_ERROR_NOT_FOUND;
			}
			
			IFDDir::RefVec::const_iterator i = find_if(subdirs.begin(), 
																								 subdirs.end(),
																								 IFDDir::isPrimary());
				
			if (i != subdirs.end()) {
				IFDDir::Ref subdir(*i);
				ret = _getRawDataFromDir(data, subdir);
			}
			else {
				ret = OR_ERROR_NOT_FOUND;
			}
			return ret;
		}

	}
}
