/*
 * libopenraw - xtranspattern.cpp
 *
 * Copyright (C) 2015 Hubert Figuière
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

#include <stdint.h>

#include <libopenraw/consts.h>

#include "xtranspattern.hpp"

namespace OpenRaw {
namespace Internals {

/** alias the colors. */
static const uint8_t RED = OR_PATTERN_COLOUR_RED;
static const uint8_t GREEN = OR_PATTERN_COLOUR_GREEN;
static const uint8_t BLUE = OR_PATTERN_COLOUR_BLUE;

/** X-Trans CMOS pattern
 *
 * RBGBRG
 * GGRGGB
 * GGBGGR
 * BRGRBG
 * GGBGGR
 * GGRGGB
 *
 */
static const uint8_t XTRANS_PATTERN[] = {
  RED,   BLUE,  GREEN, BLUE,  RED,   GREEN,
  GREEN, GREEN, RED,   GREEN, GREEN, BLUE,
  GREEN, GREEN, BLUE,  GREEN, GREEN, RED,
  BLUE,  RED,   GREEN, RED,   BLUE,  GREEN,
  GREEN, GREEN, BLUE,  GREEN, GREEN, RED,
  GREEN, GREEN, RED,   GREEN, GREEN, BLUE
};

XTransPattern::XTransPattern()
  : MosaicInfo(OR_CFA_PATTERN_NON_RGB22, 6, 6)
{
  setPatternPattern(XTRANS_PATTERN, 36);
}

const XTransPattern*
XTransPattern::xtransPattern()
{
  static const XTransPattern* s_pat = new XTransPattern();

  return s_pat;
}

}
}

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0))
  tab-width:2
  c-basic-offset:2
  indent-tabs-mode:nil
  fill-column:80
  End:
*/
