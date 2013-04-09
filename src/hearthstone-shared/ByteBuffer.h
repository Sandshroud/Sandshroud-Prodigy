/***
 * Demonstrike Core
 */

#pragma once

#include "Common.h"
#include "LocationVector.h"
#include "WoWGuid.h"
#include "Log.h"
#include "int24.h"

class ByteBufferException
{
public:
	ByteBufferException(bool _add, size_t _pos, size_t _esize, size_t _size)
		: add(_add), pos(_pos), esize(_esize), size(_size)
	{
		PrintPosError();
	}

	void PrintPosError() const
	{
		sLog.outError("Attempted to %s in ByteBuffer (pos: %u size: %u) value with size: %u",
			(add ? "put" : "get"), (uint32)pos, (uint32)size, (uint32)esize);
	}
private:
	bool add;
	size_t pos;
	size_t esize;
	size_t size;
};

class SERVER_DECL ByteBuffer
{
public:
	const char* opcodename;
	const static size_t DEFAULT_SIZE = 0x1000;

	ByteBuffer(): _rpos(0), _wpos(0)
	{
		_storage.reserve(DEFAULT_SIZE);
	}

	ByteBuffer(size_t res): _rpos(0), _wpos(0)
	{
		_storage.reserve(res);
	}

	ByteBuffer(const ByteBuffer &buf): _rpos(buf._rpos), _wpos(buf._wpos), _storage(buf._storage) { }
	virtual ~ByteBuffer() {}

	void clear()
	{
		_storage.clear();
		_rpos = _wpos = 0;
		opcodename = "";
	}

	//template <typename T> void insert(size_t pos, T value) {
	//  insert(pos, (uint8 *)&value, sizeof(value));
	//}
	template <typename T> void append(T value)
	{
		EndianConvert(value);
		append((uint8 *)&value, sizeof(value));
	}

	template <typename T> void put(size_t pos,T value)
	{
		EndianConvert(value);
		put(pos,(uint8 *)&value,sizeof(value));
	}

	// stream like operators for storing data
	ByteBuffer &operator<<(bool value)
	{
		append<char>((char)value);
		return *this;
	}

	// unsigned
	ByteBuffer &operator<<(uint8 value)
	{
		append<uint8>(value);
		return *this;
	}
	ByteBuffer &operator<<(uint16 value)
	{
		append<uint16>(value);
		return *this;
	}

	ByteBuffer &operator<<(uint32 value)
	{
		append<uint32>(value);
		return *this;
	}

	ByteBuffer &operator<<(uint64 value)
	{
		append<uint64>(value);
		return *this;
	}

	// signed as in 2e complement
	ByteBuffer &operator<<(int8 value)
	{
		append<int8>(value);
		return *this;
	}

	ByteBuffer &operator<<(int16 value)
	{
		append<int16>(value);
		return *this;
	}

	ByteBuffer &operator<<(int24 value)
	{
		append<int24>(value);
		return *this;
	}

	ByteBuffer &operator<<(int32 value)
	{
		append<int32>(value);
		return *this;
	}

	ByteBuffer &operator<<(int64 value)
	{
		append<int64>(value);
		return *this;
	}

	ByteBuffer &operator<<(float value)
	{
		append<float>(value);
		return *this;
	}

	ByteBuffer &operator<<(double value)
	{
		append<double>(value);
		return *this;
	}

	ByteBuffer &operator<<(const std::string &value)
	{
		append((uint8 *)value.c_str(), value.length());
		append((uint8)0);
		return *this;
	}

	ByteBuffer &operator<<(const char *str)
	{
		append((uint8 *)str, strlen(str));
		append((uint8)0);
		return *this;
	}

	ByteBuffer &operator<<(const WoWGuid &value)
	{
		append<uint8>(value.GetNewGuidMask());
		append((uint8 *)value.GetNewGuid(), value.GetNewGuidLen());
		return *this;
	}

	// stream like operators for reading data
	ByteBuffer &operator>>(bool &value)
	{
		value = read<char>() > 0 ? true : false;
		return *this;
	}

	//unsigned
	ByteBuffer &operator>>(uint8 &value)
	{
		value = read<uint8>();
		return *this;
	}

	ByteBuffer &operator>>(uint16 &value)
	{
		value = read<uint16>();
		return *this;
	}

	ByteBuffer &operator>>(uint32 &value)
	{
		value = read<uint32>();
		return *this;
	}

	ByteBuffer &operator>>(uint64 &value)
	{
		value = read<uint64>();
		return *this;
	}

	//signed as in 2e complement
	ByteBuffer &operator>>(int8 &value)
	{
		value = read<int8>();
		return *this;
	}

	ByteBuffer &operator>>(int16 &value)
	{
		value = read<int16>();
		return *this;
	}

	ByteBuffer &operator>>(int32 &value)
	{
		value = read<int32>();
		return *this;
	}

	ByteBuffer &operator>>(int64 &value)
	{
		value = read<int64>();
		return *this;
	}

	ByteBuffer &operator>>(float &value)
	{
		value = read<float>();
		return *this;
	}

	ByteBuffer &operator>>(double &value)
	{
		value = read<double>();
		return *this;
	}

	ByteBuffer &operator>>(std::string& value)
	{
		value.clear();
		while(true)
		{
			char c = read<char>();
			if (c == 0)
				break;
			value += c;
		}
		return *this;
	}

	//! Only does X,Y,Z!
	ByteBuffer & operator << (const LocationVector & vec)
	{
		append<float>(vec.x);
		append<float>(vec.y);
		append<float>(vec.z);
		return *this;
	}

	//! Only does X,Y,Z!
	ByteBuffer & operator >> (LocationVector & vec)
	{
		vec.x = read<float>();
		vec.y = read<float>();
		vec.z = read<float>();
		return * this;
	}

	ByteBuffer &operator>>(WoWGuid &value)
	{
		uint8 field, mask = read<uint8>();
		value.Init((uint8)mask);
		for(int i = 0; i < BitCount8(mask); i++)
		{
			field = read<uint8>();
			value.AppendField(field);
		}
		return *this;
	}

	uint8 operator[](size_t pos)
	{
		return read<uint8>(pos);
	}

	size_t rpos()
	{
		return _rpos;
	}

	size_t rpos(size_t rpos)
	{
		_rpos = rpos;
		return _rpos;
	}

	void rfinish()
	{
		_rpos = wpos();
	}

	size_t wpos()
	{
		return _wpos;
	}

	size_t wpos(size_t wpos)
	{
		_wpos = wpos;
		return _wpos;
	}

	template<typename T> void read_skip() { read_skip(sizeof(T)); }
	template<> inline void read_skip<char*>() { std::string temp; *this >> temp; }
	template<> inline void read_skip<char const*>() { read_skip<char*>(); }
	template<> inline void read_skip<std::string>() { read_skip<char*>(); }

	void read_skip(size_t skip)
	{
		if(_rpos + skip > size())
			throw ByteBufferException(false, _rpos, skip, size());
		_rpos += skip;
	}

	template <typename T> T read()
	{
		if(_rpos + sizeof(T) > size())
			throw ByteBufferException(false, _rpos, sizeof(T), size());
		T r = read<T>(_rpos);
		_rpos += sizeof(T);
		return r;
	}

	template <typename T> T read(size_t pos) const
	{
		if(pos + sizeof(T) > size())
			throw ByteBufferException(false, pos, sizeof(T), size());
		T val = *((T const*)&_storage[pos]);
		EndianConvert(&val);
		return val;
	}

	void read(uint8 *dest, size_t len)
	{
		if(_rpos  + len > size())
			throw ByteBufferException(false, _rpos, len, size());
		memcpy(dest, &_storage[_rpos], len);
		_rpos += len;
	}

	const uint8 *contents() const { return &_storage[0]; };

	HEARTHSTONE_INLINE size_t size() const { return _storage.size(); };

	// one should never use resize probably
	void resize(size_t newsize)
	{
		_storage.resize(newsize);
		_rpos = 0;
		_wpos = size();
	}

	void reserve(size_t ressize)
	{
		if (ressize > size()) _storage.reserve(ressize);
	}

	// appending to the end of buffer
	void append(const std::string& str) { append((uint8 *)str.c_str(),str.size() + 1); }
	void append(const char *src, size_t cnt) { return append((const uint8 *)src, cnt); }
	void append(const uint8 *src, size_t cnt)
	{
		if(!cnt)
			return;

		// noone should even need uint8buffer longer than 10mb
		// if you DO need, think about it
		// then think some more
		// then use something else
		// -- qz
		ASSERT(size() < 10000000);

		if (_storage.size() < _wpos + cnt)
			_storage.resize(_wpos + cnt);

		memcpy(&_storage[_wpos], src, cnt);
		_wpos += cnt;
	}

	void append(const ByteBuffer& buffer) { if(buffer.size() > 0) append(buffer.contents(),buffer.size()); }

	void put(size_t pos, const uint8 *src, size_t cnt)
	{
		if(pos + cnt > size())
			throw ByteBufferException(true, pos, cnt, size());
		memcpy(&_storage[pos], src, cnt);
	}
	//void insert(size_t pos, const uint8 *src, size_t cnt) {
	//  std::copy(src, src + cnt, inserter(_storage, _storage.begin() + pos));
	//}

	void hexlike()
	{
		if(sLog.IsOutProccess())
		{
			uint32 j = 1, k = 1;
			printf("STORAGE_SIZE: %u\n", (unsigned int)size() );
			for(uint32 i = 0; i < size(); i++)
			{
				if ((i == (j*8)) && ((i != (k*16))))
				{
					if (read<uint8>(i) < 0x0F)
					{
						printf("| 0%X ", read<uint8>(i) );
					}
					else
					{
						printf("| %X ", read<uint8>(i) );
					}

					j++;
				}
				else if (i == (k*16))
				{
					rpos(rpos()-16);	// move read pointer 16 places back
					printf(" | ");	  // write split char

					for (int x = 0; x < 16; x++)
					{
						printf("%c", read<uint8>(i-16 + x) );
					}

					if (read<uint8>(i) < 0x0F)
					{
						printf("\n0%X ", read<uint8>(i) );
					}
					else
					{
						printf("\n%X ", read<uint8>(i) );
					}

					k++;
					j++;
				}
				else
				{
					if (read<uint8>(i) < 0x0F)
					{
						printf("0%X ", read<uint8>(i) );
					}
					else
					{
						printf("%X ", read<uint8>(i) );
					}
				}
			}
			printf("\n");
		}
	}

	HEARTHSTONE_INLINE void reverse()
	{
		std::reverse(_storage.begin(), _storage.end());
	}

protected:
	// read and write positions
	size_t _rpos, _wpos;
	std::vector<uint8> _storage;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <typename T> ByteBuffer &operator<<(ByteBuffer &b, std::vector<T> v)
{
	b << (uint32)v.size();
	for (typename std::vector<T>::iterator i = v.begin(); i != v.end(); i++) {
		b << *i;
	}
	return b;
}

template <typename T> ByteBuffer &operator>>(ByteBuffer &b, std::vector<T> &v)
{
	uint32 vsize;
	b >> vsize;
	v.clear();
	while(vsize--) {
		T t;
		b >> t;
		v.push_back(t);
	}
	return b;
}

template <typename T> ByteBuffer &operator<<(ByteBuffer &b, std::list<T> v)
{
	b << (uint32)v.size();
	for (typename std::list<T>::iterator i = v.begin(); i != v.end(); i++) {
		b << *i;
	}
	return b;
}

template <typename T> ByteBuffer &operator>>(ByteBuffer &b, std::list<T> &v)
{
	uint32 vsize;
	b >> vsize;
	v.clear();
	while(vsize--) {
		T t;
		b >> t;
		v.push_back(t);
	}
	return b;
}

template <typename K, typename V> ByteBuffer &operator<<(ByteBuffer &b, std::map<K, V> &m)
{
	b << (uint32)m.size();
	for (typename std::map<K, V>::iterator i = m.begin(); i != m.end(); i++) {
		b << i->first << i->second;
	}
	return b;
}

template <typename K, typename V> ByteBuffer &operator>>(ByteBuffer &b, std::map<K, V> &m)
{
	uint32 msize;
	b >> msize;
	m.clear();
	while(msize--) {
		K k;
		V v;
		b >> k >> v;
		m.insert(make_pair(k, v));
	}
	return b;
}
