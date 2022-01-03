#include "../includes/includes.h"

int	set_rrr(t_list **stack_a, t_list **stack_b, t_info strct)
{
	int	min_a;
	int	min_b;
	int	i;

	i = 0;
	min_a = min(strct.nb_ra, strct.nb_rra);
	min_b = min(strct.nb_rb, strct.nb_rrb);
	if (min_a == strct.nb_rra && min_b == strct.nb_rrb)
	{
		while (i < min(min_a, min_b))
		{
			rrx(stack_a, "");
			rrx(stack_b, "rrr\n");
			i++;
		}
		if (min_a < min_b)
			do_(stack_b, (min_b - i), rrx, "rrb\n");
		else
			do_(stack_a, (min_a - i), rrx, "rra\n");
		return (1);
	}
	return (0);
}

int	set_rr(t_list **stack_a, t_list **stack_b, t_info strct)
{
	int	min_a;
	int	min_b;
	int	i;

	i = 0;
	min_a = min(strct.nb_ra, strct.nb_rra);
	min_b = min(strct.nb_rb, strct.nb_rrb);
	if (min_a == strct.nb_ra && min_b == strct.nb_rb)
	{
		while (i < min(min_a, min_b))
		{
			rx(stack_a, "");
			rx(stack_b, "rr\n");
			i++;
		}
		if (min_a < min_b)
			do_(stack_b, (min_b - i), rx, "rb\n");
		else
			do_(stack_a, (min_a - i), rx, "ra\n");
		return (1);
	}
	return (0);
}

int	choose_op(t_list **stack_a, t_list **stack_b, t_info strct)
{
	if (set_rr(stack_a, stack_b, strct))
		return (1);
	if (set_rrr(stack_a, stack_b, strct))
		return (1);
	else
	{

		if (strct.nb_ra > strct.nb_rra)
			do_(stack_a, strct.nb_rra, rrx, "rra\n");
		else
			do_(stack_a, strct.nb_ra, rx, "ra\n");
		if (strct.nb_rb >= strct.nb_rrb)
			do_(stack_b, strct.nb_rrb, rrx, "rrb\n");
		else
			do_(stack_b, strct.nb_rb, rx, "rb\n");
	}
	return (0);
}
