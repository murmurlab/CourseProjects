#include "include.h"

void	assign_op(t_utils *utils)
{
	if (utils->direction & 0x00000000FFFFFFFF)
	{
		if (utils->c == 'a')
			utils->op = strcln("rra\n");
		else if (utils->c == 'b')
			utils->op = strcln("rrb\n");
		else if ((unsigned char)utils->c == 222)
			utils->op = strcln("rrr\n");
	}
	else
	{
		if (utils->c == 'a')
			utils->op = strcln("ra\n");
		else if (utils->c == 'b')
			utils->op = strcln("rb\n");
		else if ((unsigned char)utils->c == 222)
			utils->op = strcln("rr\n");
	}
}

int	run_ops(t_sort *sort)
{
	if (!sort->a_b[0] && !sort->a_b[1])
		return (1);
	if (sort->a_b[0])
	{
		sort->pvt[0] = go_single((sort->abs > lp_len(sort->stacks->stack_a) / \
            2), 'a', sort->stacks);
		sort->a_b[0]--;
	}
	if (sort->a_b[1])
	{
		sort->pvt[1] = go_single((sort->abs_b > lp_len(sort->stacks->stack_b) \
						/ 2), 'b', sort->stacks);
		sort->a_b[1]--;
	}
	sort->op = sort->pvt[0] | sort->pvt[1];

	if ((sort->op) == 0b00000011)
	{
		cmd(&sort->stacks->stack_a, &sort->stacks->stack_b, "rr\n", 1);
		return (2);
	}
	else if (sort->op == 0b00001100)
	{
		cmd(&sort->stacks->stack_a, &sort->stacks->stack_b, "rrr\n", 1);
		return (2);
	}
	return (0);
}

void	triple_sort(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = (int)(size_t)(lp_nod(stacks->stack_a, 0)[0]);
	b = (int)(size_t)(lp_nod(stacks->stack_a, 1)[0]);
	c = (int)(size_t)(lp_nod(stacks->stack_a, 2)[0]);

	if (a < b && b > c && a < c)
	{
		cmd(&stacks->stack_a, &stacks->stack_b, "sa\n", 1);
		cmd(&stacks->stack_a, &stacks->stack_b, "ra\n", 1);
	}
	else if (a > b && b < c && a < c)
		cmd(&stacks->stack_a, &stacks->stack_b, "sa\n", 1);
	else if (a > b && b > c && a > c)
	{
		cmd(&stacks->stack_a, &stacks->stack_b, "sa\n", 1);
		cmd(&stacks->stack_a, &stacks->stack_b, "rra\n", 1);
	}
	else if (a < b && b > c && a > c)
		cmd(&stacks->stack_a, &stacks->stack_b, "rra\n", 1);
	else if (a > b && b < c && a > c)
		cmd(&stacks->stack_a, &stacks->stack_b, "ra\n", 1);
}

int	calc_moves(t_stacks *stacks, int index)
{
	int	val;
	int	move_a;
	int	move_b;

	move_b = index;
	val = (int)(lp_nod(stacks->stack_b, index)[0]);
	move_a = between(stacks->stack_a, val);
	move_a = midlen(move_a, lp_len(stacks->stack_a));
	move_b = midlen(move_b, lp_len(stacks->stack_b));
	return (move_a + move_b);
}

int	cost(t_stacks *stacks)
{
	int	index;
	int	len;
	int	cost[2];

	index = 0;
	len = lp_len(stacks->stack_b);
	cost[0] = 0x7FFFFFFF;
	while (index < len)
	{
		if (cost[0] > calc_moves(stacks, index))
			cost[0] = calc_moves(stacks, index), cost[1] = index;
		index++;
	}
	return (cost[1]);
}