#if !defined(MUTANT_STACK_TPP)
# define MUTANT_STACK_TPP

template <
	class T,
	class Container
> MutantStack<T, Container>::MutantStack(const Container& cont)
	: MutantStack::stack::stack(cont) { }

template <
	class T,
	class Container
> MutantStack<T, Container>::~MutantStack() { }

template <
	class T,
	class Container
> MutantStack<T, Container>::MutantStack(MutantStack& copy) : MutantStack::stack::stack(copy) {
	
}

template <
	class T,
	class Container
> MutantStack<T, Container>& MutantStack<T, Container>::operator=(MutantStack& rvalue) {
	if (this != &rvalue)
		MutantStack::stack::operator=(rvalue);
	return (*this);
}

template <
	class T,
	class Container
> typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return (this->c.begin());
}

template <
	class T,
	class Container
> typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
	return (this->c.end());
}

#endif // MUTANT_STACK_TPP
