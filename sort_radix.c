/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:22:05 by darotche          #+#    #+#             */
/*   Updated: 2023/10/12 16:19:07 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index(t_stack *stack_a, int lst_size)
{
	t_stack	*current;
	t_stack	*max;
	int		i;
	int		max_index;

	i = 0;
	while (i <= lst_size)
	{
		current = stack_a;
		max = NULL;
		max_index = 0;
		while (current != NULL)
		{
			if (current->index > max_index)
			{
				max_index = current->index;
				max = current;
			}
			current = current->next;
		}
		i++;
	}
	return (max_index);
}

void	indexate(t_stack *stack_a, int lst_size)
{
	t_stack	*current;
	t_stack	*min;
	bool	*has_i;
	int		i;
	int		min_val;

	i = 1;
	while (i <= lst_size)
	{
		has_i = false;
		current = stack_a;
		min = NULL;
		min_val = 2147483647;
		while (current)
		{
			if (current->value <= min_val && !current->has_i)
			{
				min_val = current->value;
				min = current;
			}
			current = current->next;
		}
		min->has_i = true;
		min->index = i++;
	}
}

void	radix(t_stack **stack_a, t_stack **stack_b, int max_index)
{
	int		i;
	int		j;
	int		list_size;
	int		max_bits;

	list_size = lst_size(*stack_a);
	max_bits = 0;
	i = 0;
	while (max_index >> max_bits != 0)
		max_bits ++;
	while (i < max_bits && lst_size(*stack_a) > 2)
	{
		j = 0;
		while (j++ < list_size && lst_size(*stack_a) > 2)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate(stack_a, "ra\n");
			else
				push(stack_a, stack_b, "pb\n");
		}
		while (lst_size(*stack_b) > 0)
			push(stack_b, stack_a, "pa\n");
		i++;
	}
}
