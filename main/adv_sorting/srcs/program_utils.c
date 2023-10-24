#include "include.h"

void	go(long len, long direction, char c, t_stacks *stacks)
{
	t_utils	utils;

	utils.flag = 0;
	utils.direction = direction;
	utils.c = c;
	utils.arr[0] = 'p';
	utils.arr[1] = (((c & 127) == 'a') * 'b') + ((c & 127) == 'b') * 'a' ;
	utils.arr[2] = '\n';
	utils.arr[3] = 0;
	if ((c & 127) == 'a')
		utils.stack = &stacks->stack_a;
	if ((c & 127) == 'b')
		utils.stack = &stacks->stack_b;
	assign_op(&utils);
	while (len & 0x00000000FFFFFFFF)
	{
		if ((len & 0x00000000FFFFFFFF) <= 0)
			break ;
		if (((len / (long)0x100000000) > (int)((*(utils.stack))[0])) &&
			!(direction & 0xFFFFFFFF00000000))
			cmd(&stacks->stack_a, &stacks->stack_b, utils.arr, 1);
		else
			cmd(&stacks->stack_a, &stacks->stack_b, utils.op, 1);
		len = ((len & 0xFFFFFFFF) - 1) | (len & 0xFFFFFFFF00000000);
	}
	free(utils.op);
}

char	go_single(long direction, char c, t_stacks *stacks)
{
	t_link	*stack;
	t_utils	utils;

	utils.direction = direction;
	utils.c = c;
	if ((c & 127) == 'a')
		stack = &stacks->stack_a;
	if ((c & 127) == 'b')
		stack = &stacks->stack_b;
	else
		stack = &stacks->stack_a;
	assign_op(&utils);
	if (!xstrncmp(utils.op, "ra\n", 4))
		return (free(utils.op), 0b00000001);
	else if (!xstrncmp(utils.op, "rb\n", 4))
		return (free(utils.op), 0b00000010);
	else if (!xstrncmp(utils.op, "rra\n", 5))
		return (free(utils.op), 0b00000100);
	else if (!xstrncmp(utils.op, "rrb\n", 5))
		return (free(utils.op), 0b00001000);
	return (0);
}

int	case1(t_sort *sort, int *gap, int c, t_link *stack)
{
	gap[0] = get_closest(*stack, sort->pvt[0], sort->pvt[1]);
	if (gap[0] == -1)
		return (1);
	go(((gap[0] % lp_len(*stack)) + (gap[0] >= lp_len(*stack))) | \
	((long)sort->pvt[0]) * (long)0x100000000, (gap[0] >= \
	lp_len(*stack)), (c & 127), sort->stacks);
	return (0);
}

void	case2(t_sort *sort, int *gap, int c, int len)
{
	if (gap[1] < len - gap[0])
		go(gap[1] | ((long)sort->pvt[0]) * (long)0x100000000, 0,
			(c & 127), sort->stacks);
	else
		go((len - gap[0]) | ((long)sort->pvt[0]) * (long)0x100000000, 1,
			(c & 127), sort->stacks);
}

void	case3(t_sort *sort, int *gap, int c, int len)
{
	if (gap[0] < len - gap[1])
		go(gap[0] | ((long)sort->pvt[0]) * (long)0x100000000, 0,
			(c & 127), sort->stacks);
	else
		go((len - gap[1]) | ((long)sort->pvt[0]) * (long)0x100000000, 1,
			(c & 127), sort->stacks);
}

int	go_path(t_sort *sort , int len, int c)
{
	t_link	*stack;

	sort->arr = (char [4]){'p', (((c & 127) == 'a') * 'b') + ((c & 127) == \
	'b') * 'a', '\n', 0};
	if ((c & 127) == 'a')
		stack = &sort->stacks->stack_a;
	if ((c & 127) == 'b')
		stack = &sort->stacks->stack_b;
	while (lp_len(*stack) + 1 != (len / 2) + sort->pvt[1] && lp_len(*stack) > 3)
	{
		sort->gap = biggest_gap((int [2]){0, 0}, sort->pvt, *stack,
				lp_len(*stack));
		if (!sort->gap[0] || !sort->gap[1])
		{
			if (case1(sort, sort->gap, c, stack) && (free(sort->gap), 1))
				break ;
		}
		else if (sort->gap[0] > sort->gap[1])
			case2(sort, sort->gap, c, len);
		else if (sort->gap[0] <= sort->gap[1])
			case3(sort, sort->gap, c, len);
		if (sort->pvt[0] >= (int)((*stack)[0]))
			cmd(&sort->stacks->stack_a, &sort->stacks->stack_b, sort->arr, 1);
	free(sort->gap);
	}
	return (1);
}
