#define MAX_VAL 750
#include "common.hpp"
#include "Array.hpp"

int main()
{
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
		return 0;
	}

	{
		int* a = new int[0];
		delete[] a;
		Array<string> test(5);
		for (size_t i = 0; i < test.size(); i++)
			test[i] = string("empty");	
		test[2] = string("test");
		
		Array<string> test2(test);
		test2[3] = string("test2");

		Array<string> test3;
		Array<string> test4(0);
		cout << "test==============================" << endl;
		for (size_t i = 0; i < test.size(); i++)
		{
			cout << "i1: " << i << " " << test[i] << endl;
		}
		cout << "==============================" << endl;
		cout << "test2==============================" << endl;
		for (size_t i = 0; i < test2.size(); i++)
		{
			cout << "i2: " << i << " " << test2[i] << endl;
		}
		cout << "==============================" << endl;
		cout << "test==============================" << endl;
		for (size_t i = 0; i < test.size(); i++)
		{
			cout << "i1: " << i << " " << test[i] << endl;
		}
		cout << "==============================" << endl;
		test2 = test;
		cout << "test2==============================" << endl;
		for (size_t i = 0; i < test2.size(); i++)
		{
			cout << "i2: " << i << " " << test2[i] << endl;
		}
		cout << "==============================" << endl;
		cout<< endl;
	}
	// std::exit(0);
	return 0;
}
