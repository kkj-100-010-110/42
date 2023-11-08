#ifndef LINEAR_HPP_
#define LINEAR_HPP_

#include "Vector.hpp"
#include "Matrix.hpp"

// ex01
template <typename T>
Vector<T> linear_combination(std::vector<std::vector<T>> vectors, std::vector<T> coefs)
{
	Vector<T> result;
	auto it = coefs.begin();

	for (const auto &v : vectors)
	{
		Vector<T> temp = v;
		temp.scl(*it);
		if (it == coefs.begin())
			result = temp;
		else
			result = result + temp;
		it++;
	}

	return result;
}

template <typename T>
Vector<T> linear_combination(std::vector<std::vector<T>> vectors,
							 std::initializer_list<T> coefs)
{
	Vector<T> result;
	auto it = coefs.begin();

	for (const auto &v : vectors)
	{
		Vector<T> temp = v;
		temp.scl(*it);
		if (it == coefs.begin())
			result = temp;
		else
			result = result + temp;
		it++;
	}

	return result;
}

template <typename T>
Vector<T> linear_combination(std::initializer_list<Vector<T>> vectors,
							 std::vector<T> coefs)
{
	Vector<T> result;
	auto it = coefs.begin();

	for (const auto &v : vectors)
	{
		Vector<T> temp = v;
		temp.scl(*it);
		if (it == coefs.begin())
			result = temp;
		else
			result = result + temp;
		it++;
	}

	return result;
}

template <typename T>
Vector<T> linear_combination(std::initializer_list<Vector<T>> vectors,
							 std::initializer_list<T> coefs)
{
	Vector<T> result;
	auto it = coefs.begin();

	for (const auto &v : vectors)
	{
		Vector<T> temp = v;
		temp.scl(*it);
		if (it == coefs.begin())
			result = temp;
		else
			result = result + temp;
		it++;
	}

	return result;
}

// ex02
float lerp(float A, float B, float alpha)
{
	return A * (1 - alpha) + B * alpha;
}

template <typename T>
Vector<T> lerp(Vector<T> u, Vector<T> v, float t)
{
	u.scl(1 - t);
	v.scl(t);
	return u + v;
}

template <typename T>
Matrix<T> lerp(Matrix<T> u, Matrix<T> v, float t)
{
	u.scl(1 - t);
	v.scl(t);
	return u + v;
}

#endif