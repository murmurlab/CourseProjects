#include "easyfind.hpp"
#include <vector>
#include <iterator>

// int ast(std::vector a){
// 	return 1;
// }

int main() try
{
	std::vector<int>v;
	// (void)std::begin(v);
	// v.push_back("a");
	// v.push_back("ax");
	// v.push_back("axa");
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(33);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(999);
	// cout << v[0] << endl;
	// cout << *v.begin() << endl;
	// std::vector<int>::iterator a();
	// easyfind(v, 3);
	// std::vector<int>::iterator x = std::find(v.begin(), v.end(), "axa");
	// cout << *(v.end()) << endl;

	{
		std::vector<int>::iterator x = easyfind(v, 999);
		cout << *x << endl;
	}
	{
		std::vector<int>::iterator x = easyfind(v, 42);
		cout << *x << endl;
	}
	// cout <<  << endl;
	// if ((*x).data())
	// 	cout << *x << endl;
	// else
	// 	cout << "NULL" << endl;
	return 0;
} catch (exception &e) {
	cout << e.what() << endl;
}
