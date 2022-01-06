/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:17:09 by adriouic          #+#    #+#             */
/*   Updated: 2022/01/06 11:17:14 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/includes.h"

int	nb_ra(t_list *stack_a, int num)
{
	int	nb;

	nb = 0;
	while (stack_a && *(int *)stack_a->content != num)
	{
		stack_a = stack_a->next;
		nb++;
	}
	return (nb);
}

int	nb_rb(t_list *stack_b, t_stack stacks_ab, int num)
{
	t_list	*tmp;
	int		nb;
	int		i;
	int		p;

	i = 1;
	nb = -42;
	p = INT_MAX;
	if (!stack_b)
		return (0);
	tmp = stack_b;
	while (stack_b)
	{
		if (*(int *)stack_b->content > num && *(int *)stack_b->content < p)
		{
			nb = i;
			p = *(int *)stack_b->content;
		}
		i++;
		stack_b = stack_b->next;
	}
	if (nb == -42)
		return (max_uptop(tmp) % stacks_ab.size_b);
	return (nb % stacks_ab.size_b);
}

int	total(t_info strct)
{
	int	min_a;
	int	min_b;
	int	t;

	min_a = min(strct.nb_ra, strct.nb_rra);
	min_b = min(strct.nb_rb, strct.nb_rrb);
	t = min_b + min_a;
	if (min_a == strct.nb_rra && min_b == strct.nb_rrb)
		t -= min(min_a, min_b);
	else if (min_a == strct.nb_ra && min_b == strct.nb_rb)
		t -= min(min_a, min_b);
	return (t);
}

void	max_to_top(t_list **stack_b, int nb_t, char *s1, char *s2)
{
	char	*str;
	int		size;
	int		(*f)();

	f = rx;
	str = s1;
	size = ft_lstsize(*stack_b);
	if (nb_t > size / 2)
	{
		str = s2;
		f = rrx;
		nb_t = size - nb_t;
	}
	while (nb_t--)
		f(stack_b, str);
}
