#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <vector>
#include <deque>
#include <typeinfo>
#include <sys/time.h>
#include <iomanip>

template<typename T, typename Container = std::vector<T> >
class PmergeMe : public Container
{
private:
	Container m_temp;
	struct timeval m_time;
	int K;

public:
	PmergeMe(){}
	PmergeMe(const PmergeMe<T>& pm)
	{
		for (int i = 0; i < static_cast<int>(pm.size()); i++)
			this->push_back(pm.at(i));
	}
	PmergeMe& operator = (const PmergeMe<T>& pm)
	{
		for (int i = 0; i < static_cast<int>(pm.size()); i++)
			this->push_back(pm.at(i));
	}
	~PmergeMe(){}


	void insertion(int pos, int size)
	{
		int i, j, target;

		for (i = pos; i < size; i++)
		{
			target = this->at(i + 1);
			for (j = i + 1; j > pos && this->at(j - 1) > target; j--)
				this->at(j) = this->at(j - 1);
			this->at(j) = target;
		}
	}

	void sort()
	{
		struct timeval begin, end;
		//K = 1; // merge sort
		//K = this->size(); // insertion sort
		K = 5;

		gettimeofday(&begin, NULL);

		for (int i = 0; i < static_cast<int>(this->size()); i++)
			m_temp.push_back(0);

		mergeSort(0, this->size() - 1);

		gettimeofday(&end, NULL);
		m_time.tv_sec = end.tv_sec - begin.tv_sec;
		m_time.tv_usec = end.tv_usec - begin.tv_usec;
	}

	void mergeSort(int left, int right)
	{
		int middle;

		//if (left < right) // merge
		if (right - left > K)
		{
			middle = (left + right) / 2;
			mergeSort(left, middle);
			mergeSort(middle + 1, right);
			merge(left, middle, right);
		}
		else
			insertion(left, right);
	}

	void merge(int left, int middle, int right)
	{
		int left_idx = left, right_idx = middle + 1, sorted_idx = left;

		while (left_idx <= middle && right_idx <= right)
		{
			if (this->at(left_idx) <= this->at(right_idx))
				m_temp[sorted_idx++] = this->at(left_idx++);
			else
				m_temp[sorted_idx++] = this->at(right_idx++);
		}

		if (left_idx > middle)
		{
			for (int i = right_idx; i <= right; i++)
				m_temp[sorted_idx++] = this->at(i);
		}
		else
		{
			for (int i = left_idx; i <= middle; i++)
				m_temp[sorted_idx++] = this->at(i);
		}

		for (int i = left; i <= right; i++)
			this->at(i) = m_temp[i];
	}

	std::string getType(std::string str)
	{
		return str.find("vector") == std::string::npos ? "deque" : "vector";
	}

	void print()
	{
		for (int i = 0; i < static_cast<int>(this->size()); i++)
			std::cout << this->at(i) << " ";
		std::cout << std::endl;
	}

	void printTimeType()
	{
		std::cout << "Time to process a range of " << this->size();
		std::cout << " elements with std::" << getType(typeid(this).name());
		std::cout << "\t: " << m_time.tv_sec << ".";
		std::cout.width(6);
		std::cout.fill('0');
		std::cout << m_time.tv_usec << " um" << std::endl;
	}
};

#endif
