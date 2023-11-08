#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <iostream>
#include <vector>
#include <string>

#include <iomanip>
#include <cmath> //fma
#include <type_traits> // template type check

#include "Vector.hpp"
// customising exception?

template <typename T>
class Vector;

template <typename T>
class Matrix
{
private:
	std::vector<std::vector<T>> _matrix;
	std::vector<T>              _1dMatrix;
	size_t                      _row;
	size_t                      _column;

public:
	static_assert(std::is_same_v<T, int>
	|| std::is_same_v<T, long>
	|| std::is_same_v<T, float>
	|| std::is_same_v<T, double>
	|| std::is_same_v<T, Matrix>
	, "Wrong type of template");

	Matrix()
		: _matrix(0)
		, _1dMatrix(0)
		, _row(0)
		, _column(0)
	{}
	
	Matrix(std::initializer_list<std::initializer_list<T>> data)
	{
		for (const auto &row : data)
		{
			std::vector<T> tmp;
			for (const auto &e : row)
			{
				tmp.push_back(e);
				_1dMatrix.push_back(e);
			}
			_matrix.push_back(tmp);
		}
		_row = _matrix.size();
		_column = _matrix.at(0).size();
	}
	
	Matrix(std::initializer_list<T> data)
	{
		_row = 1;
		std::vector<T> tmp;
		for (const auto &e : data)
		{
			tmp.push_back(e);
			_1dMatrix.push_back(e);
		}
		_column = _1dMatrix.size();
		_matrix.push_back(tmp);
	}

	Matrix(std::vector<std::vector<T>> data)
	{ 
		_matrix = data;
		for (int i = 0; i < _matrix.size(); i++)
		{
			for (int j = 0; j < _matrix.at(i).size(); j++)
			{
				_1dMatrix.push_back(_matrix[i][j]);
			}
		}
		_row = _matrix.size();
		_column = _matrix.at(0).size();
	}

	Matrix(std::vector<T> data, size_t row, size_t column)
	{
		_1dMatrix = data;
		_matrix.resize(row);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				_matrix.at(i).push_back(data.at(i * column + j));
			}
		}
		_row = row;
		_column = column;
	}

	Matrix<T>& operator = (const Matrix<T>& obj)
	{
		_matrix = obj._matrix;
		_1dMatrix = obj._1dMatrix;
		_row = obj._row;
		_column = obj._column;
		return *this;
	}

	Matrix<T> operator + (const Matrix<T>& operand)
	{
		if (_row != operand._row || _column != operand._column)
		{
			std::cout << "Not Same Size" << std::endl;
			return *this;
		}
		Matrix<T> result = *this;
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _column; j++)
			{
				result._1dMatrix[i * _column + j] = result._matrix[i][j] += operand._matrix[i][j];
			}
		}
		return result;
	}

	Matrix<T> operator - (const Matrix<T>& operand)
	{
		if (_row != operand._row || _column != operand._column)
		{
			std::cout << "Not Same Size" << std::endl;
			return *this;
		}
		Matrix<T> result = *this;
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _column; j++)
			{
				result._1dMatrix[i * _column + j] = result._matrix[i][j] -= operand._matrix[i][j];
			}
		}
		return result;
	}

	// incomplete
	// Matrix<T> operator * (const Matrix<T>& operand)
	// {
	// 	//  m x n * n x r
	// 	if (_column != operand._row)
	// 	{
	// 		std::cerr << "Error: size doesn't match" << std::endl;
	// 		return *this; // modify
	// 	}
	// 	Matrix<T> result;
	// 	result._matrix.resize(_row);
	// 	for (int i = 0; i < _matrix.size(); i++)
	// 	{
	// 		std::vector<T> vec = _matrix[i];
	// 	}
	// }

	friend std::ostream& operator << (std::ostream& out, const Matrix<T>& matrix)
	{
		out << "Shape: " << matrix.getShape() << std::endl;
		for (int i = 0; i < matrix.getRow(); i++)
		{
			out << "[ ";
			for (int j = 0; j < matrix.getColumn(); j++)
			{
				out.width(5);
				out << matrix.getMatrix()[i][j];
			}
			out << " ]" << std::endl;
		}
		return out;
	}

	std::vector<std::vector<T>> getMatrix() const { return _matrix; }
	size_t getRow() const { return _row; }
	size_t getColumn() const { return _column; }

	std::string getShape() const
	{
		std::string result = std::to_string(_row);
		result += " x ";
		result += std::to_string(_column);

		return result;
	}

	bool isSquare() const
	{
		return _row != _column ? false : _row == 0 ? false : true;
	}

	void print() const
	{
		for (int i = 0; i < _row; i++)
		{
			std::cout << "[ ";
			for (int j = 0; j < _column; j++)
			{
				std::cout.width(5);
				if (std::is_same<T, float>::value || std::is_same<T, double>::value)
				{
					std::fixed;
					std::cout.precision(3);
					std::cout << _matrix[i][j];
				}
				else
				{
					std::cout << _matrix[i][j];
				}
			}
			std::cout << " ]" << std::endl;
		}
	}
	
	//void reshape(size_t row, size_t column, bool byColumn = true)
	// Vector<T> reshapeMatrixToVector() { return Vector(_1dMatrix); }

	// ex00
	void add(Matrix<T>& operand)
	{
		if (this->getShape().compare(operand.getShape()) != 0)
		{
			std::cout << "They are not the same shape." << std::endl;
			std::cout << "This instance's shape: " << this->getShape() << std::endl;
			std::cout << "Parameter's shape: " << operand.getShape() << std::endl;
			return ;
		}
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _column; j++)
			{
				_1dMatrix[i * _column + j] = _matrix[i][j] += operand._matrix[i][j];
			}
		}
	}

	void sub(Matrix<T>& operand)
	{
		if (this->getShape().compare(operand.getShape()) != 0)
		{
			std::cout << "They are not the same shape." << std::endl;
			std::cout << "This instance's shape: " << this->getShape() << std::endl;
			std::cout << "Parameter's shape: " << operand.getShape() << std::endl;
			return ;
		}
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _column; j++)
			{
				_1dMatrix[i * _column + j] = _matrix[i][j] -= operand._matrix[i][j];
			}
		}
	}
	
	void scl(T value)
	{
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _column; j++)
			{
				_1dMatrix[i * _column + j] = _matrix[i][j] *= value;
			}
		}
	}
};

#endif