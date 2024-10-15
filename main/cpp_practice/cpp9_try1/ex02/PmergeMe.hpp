#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <list>
#include <time.h>
#include <deque>

class PmergeMe
{
	private:

		static const int	K = 2; 
		char**	unsorted;
		std::deque<int> dq;
		std::list<int> vec;

		void	error();
		void	printVector(std::list<int> &v);
		void	printDq(std::deque<int> &d);
		void	printArray();

		void	parsing();
		void	sort();

		void	sortVector(int beg, int end);
		void	insertionVector(int beg, int end);
		void	mergeVector(int beg, int mid, int end);

		void	sortDq(int beg, int end);
		void	insertionDq(int beg, int end);
		void	mergeDq(int beg, int mid, int end);


	public:

		char**	getUnsorted(void) const;

		PmergeMe(char** unsorted);
		PmergeMe(PmergeMe const &src);
		PmergeMe&	operator=(PmergeMe const &assign);
		~PmergeMe(void);
};

#endif

