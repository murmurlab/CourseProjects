#include "MutantStack.hpp"
#include <list>

int main( void )
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl << endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		// 5 3 5 737 0
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
		for (;!s.empty(); s.pop()) {
			cout << "stack: " << s.top() << endl;
		}
	}
	{
		cout << endl << "=================MutantStack test================= " << endl;
		MutantStack<int> a;
		a.push(3);
		a.push(33);
		a.push(333);
		cout << "a: " << a.top() << endl << endl;
		MutantStack<int>::iterator beg = a.begin();
		MutantStack<int>::iterator end = a.end();
		cout<< *beg << " - " << *(end-1) <<endl;
		MutantStack<int> test(a);
		MutantStack<int> b;

		b = a;
		cout<< "b: " << b.top() <<endl;
		b.pop();
		cout<< "b: " << b.top() <<endl;
		b.pop();
		cout<< "b: " << b.top() <<endl;
		// b.pop();
		// cout<< "b: " << b.top() <<endl << endl;

		cout<< "a: " << a.top() <<endl;
		a.pop();
		cout<< "a: " << a.top() <<endl;
		a.pop();
		cout<< "a: " << a.top() <<endl;
		a.pop();
		// cout<< "a: " << a.top() <<endl;

		cout<< "test: " << test.top() <<endl;
		test.pop();
		cout<< "test: " << test.top() <<endl;
		test.pop();
		cout<< "test: " << test.top() <<endl;
		test.pop();
		// cout<< "test: " << test.top() <<endl;
	}
	{
		cout << endl << "=================list test================= " << endl;
		std::list<int> a;
		a.push_back(3);
		a.push_back(33);
		a.push_back(333);
		cout << "a: " << a.front() << endl << endl;
		std::list<int>::iterator beg = a.begin();
		std::list<int>::iterator end = a.end();
		std::advance(end, -1);
		cout<< *beg << " - " << *(end) <<endl;
		std::list<int> b;
		
		b = a;
		cout<< "b: " << b.back() <<endl;
		b.pop_back();
		cout<< "b: " << b.back() <<endl;
		b.pop_back();
		cout<< "b: " << b.back() <<endl;
		// b.pop_back();
		// cout<< "b: " << b.back() <<endl << endl;

		cout<< "a: " << a.back() <<endl;
		a.pop_back();
		cout<< "a: " << a.back() <<endl;
		a.pop_back();
		cout<< "a: " << a.back() <<endl;
		a.pop_back();
		// cout<< "a: " << a.top() <<endl;
	}
	{
		// https://github.com/romz8/cpp08/blob/main/ex02/main.cpp
		// Test with std::string
		std::cout << YELLOW  "\nTesting with std::string\n" RESET << std::endl;
		MutantStack<std::string> stringStack;
		stringStack.push("Check out");
		stringStack.push("How my");
		stringStack.push("MutantStack");
		stringStack.push("is");
		stringStack.push("awesome!");

		std::cout << BLUE "All elements:" RESET << std::endl;
		for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << BLUE "Top element: " RESET << stringStack.top() << std::endl;
		stringStack.pop();
		std::cout << BLUE "Top after pop: " RESET << stringStack.top() << std::endl;
		std::cout << std::endl;

		// Edge case: empty stack
		std::cout << YELLOW "\nTesting edge case with empty MutantStack<int>" RESET << std::endl;
		MutantStack<int> emptyStack;
		std::cout << "Is stack empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
		if (!emptyStack.empty()) {
			std::cout << "Unexpected non-empty stack!" << std::endl;
		}

		// Copy constructor and assignment operator
		std::cout << YELLOW "\nTesting copy and assignment (on Stack<int>)" RESET << std::endl;
		MutantStack<string> copiedStack = stringStack; // Copy constructor
		MutantStack<string> assignedStack;
		assignedStack = stringStack; // Assignment operator

		std::cout << "Copied stack size: " << copiedStack.size() << std::endl;
		std::cout << "Assigned stack size: " << assignedStack.size() << std::endl;

		
		// last edge case : cannot access the deque of underlying container (we only typdef iterators, no deque::methods)
		MutantStack<int> mstack;
		mstack.push(42);
		
		// Uncommenting the following line should cause a compilation error : `front` is a deque-specific.
		// int frontValue = mstack.front();
	}
	return 0;
}
