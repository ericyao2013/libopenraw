/*
 * libopenraw - ifdentry.h
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */


#ifndef _OPENRAW_INTERNALS_IFDENTRY_H
#define _OPENRAW_INTERNALS_IFDENTRY_H

#include <boost/shared_ptr.hpp>
#include <libopenraw/types.h>

#include "exception.h"
#include "endianutils.h"
#include "rawcontainer.h"

namespace OpenRaw {
	namespace Internals {

		class IFDFileContainer;

		class IFDEntry;

		/** Describe and IFDType */
		template <typename T>
		struct IFDTypeDesc
		{
			static const uint16_t type; /**< the EXIF enum for the type */
			static const size_t   size; /**< the storage size unit in IFD*/
			static T EL(const uint8_t* d);
			static T BE(const uint8_t* d);
			static T get(IFDEntry & e, uint32_t idx = 0)
				throw (BadTypeException, OutOfRangeException, TooBigException);
		};


		template <>
		inline uint16_t IFDTypeDesc<uint16_t>::EL(const uint8_t* b)
		{
			return EL16(b);
		}

		template <>
		inline uint16_t IFDTypeDesc<uint16_t>::BE(const uint8_t* b)
		{
			return BE16(b);
		}

		template <>
		inline uint32_t IFDTypeDesc<uint32_t>::EL(const uint8_t* b)
		{
			return EL32(b);
		}

		template <>
		inline uint32_t IFDTypeDesc<uint32_t>::BE(const uint8_t* b)
		{
			return BE32(b);
		}
		

		class IFDEntry
		{
		public:
			/** Ref (ie shared pointer) */
			typedef boost::shared_ptr<IFDEntry> Ref;

			IFDEntry(uint16_t _id, int16_t _type, int32_t _count, uint32_t _data,
							 IFDFileContainer &_container);
			virtual ~IFDEntry();

			int16_t type() const
				{
					return m_type;
				}
			
			RawContainer::EndianType endian() const;

		public:
			/** load the data for the entry 
			 * if all the data fits in m_data, it is a noop
			 * @param unit_size the size of 1 unit of data
			 * @return true if success.
			 */
			bool loadData(size_t unit_size);


			/** get the array values of type T
			 * @param T the type of the value needed
			 * @param array the storage
			 * @throw whatever is thrown
			 */
			template <typename T>
			void getArray(std::vector<T> & array)
				{
					try {
						for (uint32_t i = 0; i < m_count; i++) {
							array.push_back(IFDTypeDesc<T>::get(*this, i));
						}
					}
					catch(std::exception & e)
					{
						throw e;
					}
				}


		private:
			uint16_t m_id;
			uint16_t m_type;
			uint32_t m_count;
			uint32_t m_data; /**< raw data without endian conversion */
			bool m_loaded;
			uint8_t *m_dataptr;
			IFDFileContainer & m_container;
			template <typename T> friend struct IFDTypeDesc;
		};



		/** get the value of type T
		 * @param T the type of the value needed
		 * @param idx the index, by default 0
		 * @return the value
		 * @throw BadTypeException in case of wrong typing.
		 * @throw OutOfRangeException in case of subscript out of range
		 */
		template <typename T> 
		T IFDTypeDesc<T>::get(IFDEntry & e, uint32_t idx)
			throw (BadTypeException, OutOfRangeException, TooBigException)
		{
			if (e.m_type != IFDTypeDesc<T>::type) {
				throw BadTypeException();
			}
			if (idx + 1 > e.m_count) {
				throw OutOfRangeException();
			}
			if (!e.m_loaded) {
				e.m_loaded = e.loadData(IFDTypeDesc<T>::size);
				if (!e.m_loaded) {
					throw TooBigException();
				}
			}
			uint8_t *data;
			if (e.m_dataptr == NULL) {
				data = (uint8_t*)&e.m_data;
			}
			else {
				data = e.m_dataptr + (IFDTypeDesc<T>::size * idx);
			}
			T val;
			if (e.endian() == RawContainer::ENDIAN_LITTLE) {
				val = IFDTypeDesc<T>::EL(data);
			}
			else {
				val = IFDTypeDesc<T>::BE(data);
			}
			return val;
		}

	}
}


#endif


