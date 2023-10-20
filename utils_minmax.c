/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:46:25 by darotche          #+#    #+#             */
/*   Updated: 2023/10/12 17:07:11 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(t_stack *stack_a, int lst_size)
{
	t_stack	*current;
	t_stack	*max;
	int		i;
	int		max_value;

	i = 0;
	while (i <= lst_size)
	{
		current = stack_a;
		max = NULL;
		max_value = stack_a->value;
		while (current != NULL)
		{
			if (current->value > max_value)
			{
				max_value = current->value;
				max = current;
			}
			current = current->next;
		}
		i++;
	}
	return (max_value);
}

int	min_value(t_stack *stack_a, int lst_size)
{
	t_stack	*current;
	t_stack	*min;
	int		i;
	int		min_value;

	i = 0;
	while (i <= lst_size)
	{
		current = stack_a;
		min = NULL;
		min_value = stack_a->value;
		while (current != NULL)
		{
			if (current->value < min_value)
			{
				min_value = current->value;
				min = current;
			}
			current = current->next;
		}
		i++;
	}
	return (min_value);
}
