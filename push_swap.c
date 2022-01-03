/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:39:04 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/22 01:08:52 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/includes.h"
#include <stdio.h>

//void print_stack_l(t_list *stack){t_list *curr = stack;while(curr){printf("%d\n", *(int *)curr->content); curr = curr->next;}}
//void psl(t_list *stack, int *r){t_list *curr = stack;while(curr){printf("%d\n", r[*(int *)curr->content]); curr = curr->next;}}
//int driver(t_list **stack_a, t_list **stack_b);

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
	if (ac <= 3)
		small_stack(&stack_a, ac);
	else
		large_stack(&stack_a, &stack_b);
	free(sorted);
	free(array);
	ft_lstclear(&stack_a, free);
	return (0);
}
