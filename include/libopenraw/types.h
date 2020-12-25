/*
 * libopenraw - types.h
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

#ifndef LIBOPENRAW_TYPES_H_
#define LIBOPENRAW_TYPES_H_

/** @addtogroup public_api
 * @{
 */
/* C99 standard */
#include <stdint.h>

typedef struct _RawFile *ORRawFileRef; /**< @brief RawFile reference */
typedef struct _RawData *ORRawDataRef; /**< @brief RawData reference */
typedef struct _BitmapData *ORBitmapDataRef; /**< @brief BitmapData reference */
typedef struct _Thumbnail *ORThumbnailRef; /**< @brief Thumbnail reference */
typedef struct _IfdDir *ORIfdDirRef; /**< @brief IfdDir reference */

/** @} */

#endif
