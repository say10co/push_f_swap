/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:39:04 by adriouic          #+#    #+#             */
/*   Updated: 2022/01/06 12:43:14 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/includes.h"

int	clear_out(void *a, void *b, t_list **t_c)
{
	free(a);
	free(b);
	ft_lstclear(t_c, free);
	return (0);
}

int	main(int ac, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*array;
	int		*sorted;

	if (!check_args(&args, &ac))
		return (0);
	stack_b = NULL;
	sorted = sort_(args, --ac, &array);
	if (!sorted)
		return (0);
	stack_a = form_stack(array, sorted, ac);
	if (!stack_a)
		return (0);
	if (is_sorted(stack_a))
		return (clear_out(sorted, array, &stack_a));
	if (ac <= 3)
		small_stack(&stack_a, ac);
	else
		large_stack(&stack_a, &stack_b);
	return (clear_out(sorted, array, &stack_a));
}
