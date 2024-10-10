#if !defined(MUTANT_STACK_HPP)
# define MUTANT_STACK_HPP

# include <stack>
# include "common.hpp"

using std::stack;

template <
	class T,
	class Container = std::deque<T>
> class MutantStack : public stack<T , Container> {

	public:
		MutantStack(const Container& cont = Container());
		~MutantStack();
		MutantStack(MutantStack& copy);
		MutantStack& operator=(MutantStack& rvalue);

		typedef typename stack<T, Container>::container_type::iterator iterator;
		iterator begin();
		iterator end();
	private:

};

#include "MutantStack.tpp"

#endif // MUTANT_STACK_HPP
