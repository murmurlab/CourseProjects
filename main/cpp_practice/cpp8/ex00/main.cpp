#include "easyfind.hpp"
#include <vector>
#include <iterator>

// int ast(std::vector a){
// 	return 1;
// }

int main()
{
	std::vector<int>v;
	// (void)std::begin(v);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	// cout << v[0] << endl;
	// cout << *v.begin() << endl;
	// std::vector<int>::iterator a();
	// easyfind(v, 3);
	std::vector<int>::iterator x = std::find(v.begin(), v.end(), 3);
	cout << *x << endl;
	return 0;
}
