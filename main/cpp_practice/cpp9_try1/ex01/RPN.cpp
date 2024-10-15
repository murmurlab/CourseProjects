#include "RPN.hpp"

int RPN::is_opt(char op)
{
	if (!(op == '+' || op == '-' || op == '/' || op == '*'))
		{cout << "Invalid operator " << op << endl; exit (EXIT_FAILURE);}
	return (1);
}

void RPN::operate()
{
	int op2 = nums.top();nums.pop();
	int	op1 = nums.top();nums.pop();
	const char op0 = ops.top();ops.pop();
	nums.push(((op0 == '*') ? op1 * op2 :
			(op0 == '+') ? op1 + op2 :
			(op0 == '-') ? op1 - op2 :
			(op0 == '/') ? op1 / op2 :
			std::numeric_limits<int>::quiet_NaN()));
}
RPN::~RPN(void) { }
RPN::RPN(RPN const& src) { if (&src != this) *this = src; }

RPN::RPN(string input) : raw_exp(input)
{
	size_t	exp_size;

	if ((exp_size = raw_exp.size()) < 3) {cout << "few expression" << endl; exit (EXIT_FAILURE);}
	for (size_t i = 0; (i < exp_size) ; i++)
	{
		if (raw_exp[i] == ' ') continue ;
		if (isdigit(raw_exp[i])) {
			if (isdigit(raw_exp[i + 1]))
				{cout << "Only digit " << raw_exp[i] << raw_exp[i + 1] << endl; exit (EXIT_FAILURE);}
			nums.push(raw_exp[i] - '0');
		} else if (is_opt(raw_exp[i]))
			ops.push(raw_exp[i]);
		if (nums.size() >= 2 && ops.size() == 1)
			operate();
	}
	if (!nums.empty()) cout << nums.top() << endl;
}

RPN &	RPN::operator=(const RPN& assign)
{
	this->raw_exp = assign.raw_exp;
	return (*this);
}
