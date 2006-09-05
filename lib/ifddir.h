/*
 * libopenraw - ifddir.h
 *
 * Copyright (C) 2006 Hubert Figuiere
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


#ifndef _OPENRAW_INTERNALS_IFDDIR_H
#define _OPENRAW_INTERNALS_IFDDIR_H

#include <map>

#include <boost/shared_ptr.hpp>
#include "ifdentry.h"

namespace OpenRaw {
	namespace Internals {
		
		class IFDFileContainer;

		class IFDDir
		{
		public:
			typedef boost::shared_ptr<IFDDir> Ref;

			IFDDir(off_t _offset, IFDFileContainer & _container);
			virtual ~IFDDir();
			
      /** return the offset */
			off_t offset() const
				{
					return m_offset;
				}

			/** load the directory to memory */
			bool load();
			/** return the number of entries*/
			int numTags()
				{
					return m_entries.size();
				}
			IFDEntry::Ref getEntry(int id);
			/** get the offset of the next IFD 
			 * in absolute
			 */
			off_t nextIFD();
		private:
			off_t m_offset;
			IFDFileContainer & m_container;
			std::map<int, IFDEntry::Ref> m_entries;
		};


	}
}


#endif
