/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertD.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:17:38 by adriouic          #+#    #+#             */
/*   Updated: 2022/01/06 11:17:42 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/includes.h"

void	do_(t_list **stack_b, int nb_t, int (*f)(), char *s)
{
	while (nb_t--)
		f(stack_b, s);
}

int	max_uptop(t_list *stack_b)
{
	t_list	*curr;
	int		max;
	int		i;
	int		j;

	max = *(int *)(stack_b)->content;
	curr = stack_b;
	i = 0;
	j = 0;
	while (curr)
	{
		if (*(int *)(curr)->content > max)
		{
			max = *(int *)(curr)->content;
			j = i;
		}
		curr = curr->next;
		i++;
	}
	return (j);
}

void	min_mv(t_list *stack_a, t_list *stack_b, t_info *strct, t_stack stacks)
{
	t_info	tmp;

	tmp.nb_ra = nb_ra(stack_a, strct->num);
	tmp.nb_rb = nb_rb(stack_b, stacks, strct->num);
	tmp.nb_rra = (strct->size_a - tmp.nb_ra);
	tmp.nb_rrb = (strct->size_b - tmp.nb_rb);
	tmp.t = total(tmp);
	if (tmp.t < strct->t)
	{
		strct->nb_ra = tmp.nb_ra;
		strct->nb_rb = tmp.nb_rb;
		strct->nb_rra = tmp.nb_rra;
		strct->nb_rrb = tmp.nb_rrb;
		strct->t = tmp.t;
	}
}

t_info	*get_best(t_list *stack_a, t_list *stack_b, t_stack stacks_ab, int s)
{
	t_info	*best;
	t_list	*curr;
	int		n;

	best = (t_info *)malloc(sizeof(t_info));
	best->size_a = stacks_ab.size_a;
	best->size_b = stacks_ab.size_b;
	best->t = INT_MAX;
	n = *(int *)stack_a->content;
	best->num = n;
	curr = stack_a;
	while (curr)
	{
		n = *(int *)curr->content;
		if (!(n == s -1 || n == s -2 || n == s -3))
		{
			best->num = n;
			min_mv(stack_a, stack_b, best, stacks_ab);
		}
		curr = curr->next;
	}
	return (best);
}

int	large_stack(t_list **stack_a, t_list **stack_b)
{
	t_info	*b;
	t_stack	stacks;
	int		org_size;

	stacks.size_a = ft_lstsize(*stack_a);
	stacks.size_b = 0;
	org_size = stacks.size_a;
	while (*stack_a && stacks.size_a != 3)
	{
		b = get_best(*stack_a, *stack_b, stacks, org_size);
		choose_op(stack_a, stack_b, *b);
		px(stack_a, stack_b, "pb\n");
		free(b);
		stacks.size_b += 1;
		stacks.size_a -= 1;
	}
	three_(stack_a);
	max_to_top(stack_b, max_uptop(*stack_b), "rb\n", "rrb\n");
	get_allto_stacka(stack_a, stack_b);
	return (1);
}
