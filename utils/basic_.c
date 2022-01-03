/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:53:42 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/21 11:58:48 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/includes.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	three_(t_list **stack_a)
{
	int	one;
	int	two;
	int	three;

	one = *(int *)(*stack_a)->content;
	two = *(int *)(*stack_a)->next->content;
	three = *(int *)(*stack_a)->next->next->content;
	if (one < two && two < three)
		return (0);
	else if (three < one && one < two)
		return (rrx(stack_a, "rra\n"));
	else if (two < three && three < one)
		return (rx(stack_a, "ra\n"));
	else if (one < three && three < two)
		return (rrx(stack_a, "rra\n") + sx(stack_a, "sa\n"));
	else if (three < two && two < one)
		return (sx(stack_a, "sa\n") + rrx(stack_a, "rra\n"));
	else
		return (sx(stack_a, "sa\n"));
}

int	get_allto_stacka(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (*stack_b)
		i += px(stack_b, stack_a, "pa\n");
	return (i);
}
