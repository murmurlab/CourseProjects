#include "include.h"

void	search_builtins(t_main *shell, int cmd_off)
{
	int																	o__o;
	
	o__o = 01;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	while (o__o < 0x8)
	{
		if (!ft_strcmp(shell->cmds[cmd_off].cmd, shell->coms[o__o].name))
		{
			shell->cmds[cmd_off].builtin_offset = o__o;;
			return ;
		}
		(++o__o);
	}
	shell->cmds[cmd_off].builtin_offset = 0b00000000000000000000000000000000;;
	return ;
}
