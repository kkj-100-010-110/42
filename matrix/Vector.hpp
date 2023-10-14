#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <iostream>
#include <vector>
#include <string>

#include <iomanip>
#include <cmath> //fma
#include <type_traits> // template type check

#include "Matrix.hpp"
// customising exception?

template <typename T>
class Matrix;

template <typename T>
class Vector
{
private:
	std::vector<T>  _vector;
	bool            _isColumn = true;

public:
	//constexpr bool typeCheck()
	//{
	//    return (std::is_same_v<T, int>
	//    || std::is_same_v<T, long>
	//    || std::is_same_v<T, float>
	//    || std::is_same_v<T, double>) ? true : false;
	//}
	static_assert(std::is_same_v<T, int>
	|| std::is_same_v<T, long>
	|| std::is_same_v<T, float>
	|| std::is_same_v<T, double>
	|| std::is_same_v<T, Vector>
	, "Wrong type of template");

	Vector()
		: _vector(0)
	{}

	Vector(T num)
		: _vector(num)
	{}

	Vector(std::initializer_list<T> values, bool isColumn = true)
	{
		for (const auto &e : values)
		{
			_vector.push_back(e);
		}

		_isColumn = isColumn;
	}

	Vector(std::vector<T> data)
		: _vector(data)
	{}

	Vector(std::vector<T> data, bool isColumn)
		: _vector(data)
		, _isColumn(isColumn)
	{}

	Vector(const Vector<T>& obj)
	{
		_vector = obj._vector;
		_isColumn = obj._isColumn;
	}

	Vector& operator = (const Vector<T>& obj)
	{
		_vector = obj._vector;
		_isColumn = obj._isColumn;
		return *this;
	}

	T& operator [] (const int index) { return _vector[index]; }
	const T& operator [] (const int index) const { return _vector[index]; }

	Vector<T> operator + (const Vector<T>& operand)
	{
		if (_vector.size() != operand._vector.size())
		{
			std::cerr << "Not Same Size" << std::endl;
			return Vector<T>(*this);
		}
		Vector<T> result(*this);

		for (auto it = result._vector.begin(), it2 = operand._vector.begin();
		it != result._vector.end(); it++, it2++)
		{
			*it += *it2;
		}

		return result;
	}

	Vector<T> operator - (const Vector<T>& operand)
	{
		if (_vector.size() != operand._vector.size())
		{
			std::cerr << "Not Same Size" << std::endl;
			return Vector<T>(*this);
		}
		Vector<T> result(*this);

		for (auto it = result._vector.begin(), it2 = operand._vector.begin();
		it != result._vector.end(); it++, it2++)
		{
			*it -= *it2;
		}

		return result;
	}

	Vector<T> operator * (const Vector<T>& operand)
	{
		if (_vector.size() != operand._vector.size())
		{
			std::cerr << "Not Same Size" << std::endl;
			return Vector<T>(*this);
		}
		Vector<T> result(*this);

		for (auto it = result._vector.begin(), it2 = operand._vector.begin();
		it != result._vector.end(); it++, it2++)
		{
			*it *= *it2;
		}

		return result;
	}

	friend std::ostream& operator << (std::ostream& out, Vector<T> vector)
	{
		out << "Column: " << vector.isColumn() << std::endl;
		out << "Size: " << vector.getSize() << std::endl;
		for (const auto &e : vector.getVector())
		{
			out << "[ ";
			out.width(5);
			out << e << " ]" << std::endl;
		}
		return out;
	}

	bool isColumn() const { return _isColumn; }
	std::vector<T> getVector() const { return _vector; }

	std::string getSize() const
	{
		std::string result;
		if (_isColumn)
		{
			result = std::to_string(_vector.size());
			result += " x 1";
		}
		else
		{
			result = "1 x ";
			result += std::to_string(_vector.size());
		}

		return result;
	}

	void print() const
	{
		if (_isColumn)
		{
			for (const auto &e : _vector)
			{
				std::cout << "[ ";
				std::cout.width(5);
				if (std::is_same<T, float>::value || std::is_same<T, double>::value)
				{
					std::fixed;
					std::cout.precision(3);
					std::cout << e << " ]" << std::endl;
				}
				else
				{
					std::cout << e << " ]" << std::endl;
				}
			}
		}
		else
		{
			std::cout << "[ ";
			for (const auto &e : _vector)
			{
				if (std::is_same<T, float>::value || std::is_same<T, double>::value)
				{
					std::fixed;
					std::cout.precision(3);
					std::cout << e << " " << std::endl;
				}
				else
				{
					std::cout << e << " ";
				}
			}
			std::cout << " ]" << std::endl;
		}
	}

	// by column or row
	Matrix<T> reshapeVectorToMatrix(T row, T column, bool byRow = false)
	{
		if (row * column != _vector.size())
		{
			std::cout << "Cannot reshape because of the size matter" << std::endl;
			std::cout << "Vector size is " << this->getSize() << std::endl;
		}

		std::vector<std::vector<T>> temp;
		temp.resize(row);

		if (byRow)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					temp.at(i).push_back(_vector[i * column + j]);
				}
			}
		}
		else
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					temp.at(i).push_back(_vector[i + j * row]);
				}
			}
		}

		return Matrix(temp);
	}

	// ex00
	void add(const Vector<T>& operand)
	{
		if (this->getSize().compare(operand.getSize()) != 0)
		{
			std::cout << "They are not the same size." << std::endl;
			std::cout << "This instance's size: " << this->getSize() << std::endl;
			std::cout << "Parameter's size: " << operand.getSize() << std::endl;
			return ;
		}
		for (int i = 0; i < _vector.size(); i++)
		{
			_vector[i] += operand[i];
		}
	}

	void sub(const Vector<T>& operand)
	{
		if (this->getSize().compare(operand.getSize()) != 0)
		{
			std::cout << "They are not the same size." << std::endl;
			std::cout << "This instance's size: " << this->getSize() << std::endl;
			std::cout << "Parameter's size: " << operand.getSize() << std::endl;
			return ;
		}
		for (int i = 0; i < _vector.size(); i++)
		{
			_vector[i] -= operand[i];
		}
	}
	
	void scl(T value)
	{
		for (auto &e : _vector)
		{
			e *= value;
		}
	}

	// ex03
	T dot(Vector<T> &v)
	{
		if (_vector.size() != v._vector.size())
		{
			std::cerr << "Error: not the same size" << std::endl;
			return errno;
		}
		T result = 0;
		for (auto it = _vector.begin(), it2 = v._vector.begin(); it != _vector.end();
			it++, it2++)
		{
			result += *it * *it2;
		}
		return result;
	}

};

#endif