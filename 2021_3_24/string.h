#pragma once
#include <assert.h>
#include<windows.h>
#pragma warning(disable:4996)

namespace bit
{

	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			if (_str)
			{


				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}

		size_t size()
		{
			return _size;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(2 * _capacity);
			}
			_str[_size] = ch;
			++_size;
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		// s += 'x';
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		string& operator+=(const string& s)
		{
			append(s._str);
			return *this;
		}


	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 能存多少个有效字符的空间
	};

}