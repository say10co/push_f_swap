/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:36:50 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/22 00:50:29 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	size_a;
	int	size_b;
}t_stack;

typedef struct s_info
{
	int	nb_rb;
	int	nb_ra;
	int	nb_rra;
	int	nb_rrb;
	int	num;
	int	nb_rr;
	int	nb_rrr;
	int	t;
	int	size_a;
	int	size_b;
}t_info;

//***********actions**************
int	px(t_list **from, t_list **to, char *s);
int	rx(t_list **stack_x, char *s);
int	rrx(t_list **stack_x, char *s);
int	sx(t_list **stack, char *s);

//************basic***************
int	three_(t_list **stack_a);
int	get_allto_stacka(t_list **stack_a, t_list **stack_b);
int	min(int a, int b);
int	max(int a, int b);

//************errors***************
int	ft_strcmp(char *s1, char *s2);
int	check_args(char ***args, int *ac);

//************pushswaputils********

t_list		*form_stack(int *array, int *sorted, int ac);
int	*sort_(char **args, int ac, int **res);
int	small_stack(t_list **stack_a, int count);
int	check_double_count(char **av, int c);

//***********sort_utils************
void	swap(int *i, int *j);
int	*min_(int *array, int size);
int	is_sorted(t_list *lst);
int	get_indexof(int *array, int num);
int	sort_basic(t_list **stack_a, t_list **stack_b, int size_a);

//***********insertion_utils.c************
int	set_rrr(t_list **stack_a, t_list **stack_b, t_info strct);
int	set_rr(t_list **stack_a, t_list **stack_b, t_info strct);
int	choose_op(t_list **stack_a, t_list **stack_b, t_info strct);

//***********counters.c************
void	max_to_top(t_list **stack_b, int nb_t, char *s1, char *s2);
void	do_(t_list **stack_b, int nb_t, int (*f)(), char *s);
int		nb_rb(t_list *stack_b, t_stack stacks_ab, int num);
int		nb_ra(t_list *stack_a, int num);
int		total(t_info strct);
int		large_stack(t_list **stack_a, t_list **stack_b);
int		max_uptop(t_list *stack_b);
#endif
