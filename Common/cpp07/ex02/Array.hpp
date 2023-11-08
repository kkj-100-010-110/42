#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T* m_arr;
	unsigned int m_size;

public:
	Array()
		: m_arr(NULL), m_size(0)
	{}

	Array(unsigned int n)
		: m_arr(NULL), m_size(n)
	{
		if (n > 0)
			m_arr = new T[n]();
	}

	Array(const Array& a)
		: m_arr(NULL)
	{
		*this = a;
	}

	Array& operator = (const Array& a)
	{
		if (this != &a)
		{
			delete[] m_arr;
			m_size = a.size();
			if (m_size > 0)
			{
				m_size = a.size();
				m_arr = new T[m_size];
				for (unsigned int i = 0; i < m_size; ++i)
					m_arr[i] = a.m_arr[i];
			}
			else
				m_arr = NULL;
		}
		return *this;
	}

	~Array()
	{
		delete[] m_arr;
	}

	const T& operator [] (unsigned int idx) const
	{
		if (idx >= m_size)
			throw std::out_of_range("out of range.");
		return m_arr[idx];
	}

	T& operator [] (unsigned int idx)
	{
		if (idx >= m_size)
			throw std::out_of_range("out of range.");
		return m_arr[idx];
	}

	unsigned int size() const
	{
		return m_size;
	}
};

#endif
