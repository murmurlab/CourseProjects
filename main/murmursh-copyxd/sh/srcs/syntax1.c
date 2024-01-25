#include "include.h"

void	syntax_other(t_main *shell, t_syntax *syntax, size_t *_)
{
	if (shell->line[*_] == '\t' || shell->line[*_] == ' ')
		++*_;
	else
		syntax->zero_pipe = (syntax->simplex = (++*_, 0));
}

int		choose(t_main *shell, t_syntax *syntax, size_t *_)
{
	(void)(((shell->line[*_] == '\'') && (syntax_squote(syntax), 1)) \
	|| ((shell->line[*_] == '"') && (syntax_dquote(syntax), 1)));
	if (syntax->duplex)
		return ((*_)++, 1);
	if ((shell->line[*_] == '>' && shell->line[(*_) + 1] != '>') || \
			(shell->line[*_] == '<' && shell->line[(*_) + 1] != '<'))
	{
		if (syntax_sarrow(syntax, _))
			return (2);
	}
	else if ((shell->line[*_] == '>' && shell->line[(*_) + 1] == '>') || \
			(shell->line[*_] == '<' && shell->line[(*_) + 1] == '<'))
	{
		if (syntax_darrow(syntax, _))
			return (2);
	}
	else if (shell->line[*_] == '|')
	{
		if (syntax_pipe(shell, syntax, _))
			return (2);
	}
	else
		syntax_other(shell, syntax, _);
	return (0);
}

int		syntax_check(t_main *shell)
{
	size_t		_;
	t_syntax	syntax;
	int			result;

	syntax.undefined = 0;
	syntax.zero_pipe = 1;
	syntax.duplex = 0;
	syntax.simplex = 0;
	_ = 0;
	while (shell->line[_] == '\t' || shell->line[_] == ' ')
		_++;
	if (shell->line[_] == '\0')
		return (0);
	while (shell->line[_])
	{
		result = choose(shell, &syntax, &_);
		if (result == 2)
			break ;
	}
	++shell->cmd_ct;
	return ((syntax.duplex << 0 ) | (syntax.simplex << 8) | \
			(syntax.zero_pipe << 16) | (syntax.undefined << 24));
}
void	print_syntax_err(int errs)
{
	if (errs & 0xff000000)
		printf("shell says: I don't know what you're trying to do\n");
	if (errs & 0x00ff0000)
		printf("shell says: syntax error near expected non-exist token before "
				"`|'\n");
	if (errs & 0x0000ff00)
		printf("shell says: syntax error near unexpected token after "
				"`|', `>', `<', `>>', `<<'\n");
	if (errs & 0x000000ff)
		printf("shell says: unexpected EOF while looking for matching "
				"`'', `\"'\n");
}
