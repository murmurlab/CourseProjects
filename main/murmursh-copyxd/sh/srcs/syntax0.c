#include "include.h"

void	syntax_squote(t_syntax *syntax)
{
	if (syntax->duplex == 1)
	{
		syntax->duplex = 0;
		syntax->zero_pipe = 0;
		if (syntax->simplex)
			syntax->simplex = 0;
	}
	else if (syntax->duplex == 0)
		syntax->duplex = 1;
}

void	syntax_dquote(t_syntax *syntax)
{
	if (syntax->duplex == 2)
	{
		syntax->duplex = 0;
		syntax->zero_pipe = 0;
		if (syntax->simplex)
			syntax->simplex = 0;
	}
	else if (syntax->duplex == 0)
		syntax->duplex = 2;
}

int		syntax_pipe(t_main *shell, t_syntax *syntax, size_t *_)
{
	shell->cmd_ct++;
	if (!syntax->zero_pipe)
		syntax->zero_pipe = 1;
	else
		return (2);
	if (!syntax->simplex)
		syntax->simplex = 3;
	else
		return (2);
	++(*_);
	return (0);
}

int		syntax_sarrow(t_syntax *syntax, size_t *_)
{
	if (!syntax->simplex)
		syntax->simplex = 1;
	else if (syntax->simplex == 3)
		syntax->simplex = 1;
	else
		return (2);
	++*_;
	return (0);
}

int		syntax_darrow(t_syntax *syntax, size_t *_)
{
	if (!syntax->simplex)
		syntax->simplex = 2;
	else if (syntax->simplex == 3)
	{
		syntax->simplex = 2;
	}
	else
		return (2);
	*_ += 2;
	return (0);
}
