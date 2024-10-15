#include "PmergeMe.hpp"

#include <cctype>
#include <ctime>
#include <ios>
#include <list>

// bool is_sorted1(std::list<int>::iterator begin, std::list<int>::iterator end) {
//     if (begin == end) return true; // Boş bir koleksiyon sıralıdır.

//     std::list<int>::iterator next = begin;
//     ++next;

//     while (next != end) {
//         if (*next < *begin) {
//             return false; // Eğer bir önceki değer sonraki değerden büyükse sıralı değildir.
//         }
//         ++begin;
//         ++next;
//     }
//     return true; // Tüm değerler sıralı.
// }

// bool is_sorted2(std::deque<int>::iterator begin, std::deque<int>::iterator end) {
//     if (begin == end) return true; // Boş bir koleksiyon sıralıdır.

//     std::deque<int>::iterator next = begin;
//     ++next;

//     while (next != end) {
//         if (*next < *begin) {
//             return false; // Eğer bir önceki değer sonraki değerden büyükse sıralı değildir.
//         }
//         ++begin;
//         ++next;
//     }
//     return true; // Tüm değerler sıralı.
// }

int&	at(std::list<int>& l, size_t n) {
	std::list<int>::iterator it = l.begin();
	std::advance(it, n);
	return *it;
}

std::list<int>::iterator	nxt(std::list<int>::iterator l, size_t n) {
	std::list<int>::iterator it = l;
	std::advance(it, n);
	return it;
}

void PmergeMe::error()
{
	std::cout << "Error" << std::endl;
	exit(-1);
}

void PmergeMe::printVector(std::list<int> &v)
{
	std::list<int>::iterator	it;

	std::cout << "Vector:" ;
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::printDq(std::deque<int> &d)
{
	std::deque<int>::iterator	it;

	std::cout << "Deque:" ;
	for (it = d.begin(); it != d.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::printArray()
{
	int i = 1;
	std::cout << "Before:" ;
	while (unsorted[i])
	{
		std::cout << " " << unsorted[i];
		i++;
	}
	std::cout << std::endl;
}

void PmergeMe::parsing()
{
	int	i, j;

	i = 1;
	while (unsorted[i])
	{
		j = 0;
		while (unsorted[i][j])
		{
			if (isdigit(unsorted[i][j]) == 0)
				error();
			j++;
		}
		vec.push_back(atoi(unsorted[i]));
		dq.push_back(atoi(unsorted[i]));
		i++;
	}
	printArray();
}

void PmergeMe::sort()
{
	clock_t	start, finish;
	double	time_v, time_dq;

	std::cout << "After:" << std::endl;

	start = clock();
	sortVector(0, vec.size() - 1);
	finish = clock();
	time_v = ((double) (finish - start)) / CLOCKS_PER_SEC;
	printVector(vec);

	start = clock();
	sortDq(0, dq.size() - 1);
	finish = clock();
	time_dq = ((double) (finish - start)) / CLOCKS_PER_SEC;
	printDq(dq);

	std::cout << "Time to process a range of " << vec.size() << " elements with std::list is: "  << std::fixed << time_v  << std::endl;
	std::cout << "Time to process a range of " << dq.size() << " elements with std::deque is: "  << std::fixed << time_dq  << std::endl;
	// vec.push_back(33);
	// std::cout << is_sorted1(vec.begin(), vec.end()) << std::endl;
	// dq.push_back(332);
	// std::cout << is_sorted2(dq.begin(), dq.end()) << std::endl;

	return ;	
}



void PmergeMe::insertionDq(int beg, int end)
{
	for (int i = beg; i < end; i++)
	{
		int temp = dq[i + 1];
		int	j = i + 1;
		while (j > beg && dq[j - 1] > temp)
		{
			dq[j] = dq[j - 1];
			j--;
		}
		dq[j] = temp;
	}
}

void PmergeMe::sortVector(int beg, int end)
{
	if (end - beg > K)
	{
		int	mid = (beg + end) / 2;
		sortVector(beg, mid);
		sortVector(mid + 1, end);
		mergeVector(beg, mid, end);
	}
	else
		insertionVector(beg, end);
}

void PmergeMe::insertionVector(int beg, int end)
{
	for (int i = beg; i < end; i++)
	{
		int temp = at(vec, i + 1);
		int	j = i + 1;
		while (j > beg && at(vec, j - 1) > temp)
		{
			at(vec, j) = at(vec, j - 1);
			j--;
		}
		at(vec, j) = temp;
	}
}

void PmergeMe::mergeVector(int beg, int mid, int end)
{
	int	n1 = mid - beg + 1;
	int	n2 = end - mid;
	int	right_i = 0;
	int	left_i = 0;

	std::list<int> left(nxt(vec.begin(), beg), nxt(vec.begin(), mid + 1));
	std::list<int> right(nxt(vec.begin(), mid + 1), nxt(vec.begin(), end + 1));

	for (int i = beg; i <= end; i++)
	{
		if (right_i == n2)
		{
			at(vec, i) = at(left, left_i);
			left_i++;
		}
		else if (left_i == n1)
		{
			at(vec, i) = at(right, right_i);
			right_i++;
		}
		else if (at(right, right_i) > at(left, left_i))
		{
			at(vec, i) = at(left, left_i);
			left_i++;
		}
		else
		{
			at(vec, i) = at(right, right_i);
			right_i++;
		}
	}
}

void PmergeMe::mergeDq(int beg, int mid, int end)
{
	int	n1 = mid - beg + 1;
	int	n2 = end - mid;
	int	right_i = 0;
	int	left_i = 0;

	std::deque<int> left(dq.begin() + beg, dq.begin() + mid + 1);
	std::deque<int> right(dq.begin() + mid + 1, dq.begin() + end + 1);

	for (int i = beg; i <= end; i++)
	{
		if (right_i == n2)
		{
			dq[i] = left[left_i];
			left_i++;
		}
		else if (left_i == n1)
		{
			dq[i] = right[right_i];
			right_i++;
		}
		else if (right[right_i] > left[left_i])
		{
			dq[i] = left[left_i];
			left_i++;
		}
		else
		{
			dq[i] = right[right_i];
			right_i++;
		}
	}
}

void PmergeMe::sortDq(int beg, int end)
{
	if (end - beg > K)
	{
		int	mid = (beg + end) / 2;
		sortDq(beg, mid);
		sortDq(mid + 1, end);
		mergeDq(beg, mid, end);
	}
	else
		insertionDq(beg, end);

}

char** PmergeMe::getUnsorted(void) const
{
	return (this->unsorted);
}

PmergeMe::PmergeMe(char** unsorted) : unsorted(unsorted)
{
	parsing();
	sort();
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	return ;
}

PmergeMe &	PmergeMe::operator=(const PmergeMe &assign)
{
	this->unsorted = assign.getUnsorted();
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

