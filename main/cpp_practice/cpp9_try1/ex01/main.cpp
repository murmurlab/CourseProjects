#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (cout << "too few args" << endl, EXIT_FAILURE);
	RPN	a(argv[1]);
	return (EXIT_SUCCESS);
}

