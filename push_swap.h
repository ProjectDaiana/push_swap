/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:22:52 by darotche          #+#    #+#             */
/*   Updated: 2023/10/07 14:01:56 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	bool			has_i;
	struct s_stack	*next;	
}	t_stack;

int		check_argc(int argc, char **argv);
int		check_digits(int argc, char **argv);
int		is_sorted(t_stack *stack_a);
long	ft_atol(const char *str);
void	ft_check_dupl(t_stack *stack_a);

t_stack	*ft_newnode(int value);
t_stack	*ft_lstlast(t_stack *stack);
void	deallocate(t_stack **stack);
void	init_stack(t_stack **stack_a, int argc, char **argv);
void	ft_addback(t_stack **head, int nb);
int		lst_size(t_stack *stack_a);

void	swap(t_stack **stack, char *movement);
void	rotate(t_stack **stack, char *movement);
void	revrotate(t_stack **stack, char *movement);
void	push(t_stack **stack_a, t_stack **stack_b, char *movement);

int		max_index(t_stack *stack_a, int lst_size);
int		max_value(t_stack *stack_a, int lst_size);
int		min_value(t_stack *stack_a, int lst_size);

void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	radix(t_stack **stack_a, t_stack **stack_b, int max_value);
void	indexate(t_stack *stack_a, int lst_size);

int		main(int argc, char **argv);

#endif