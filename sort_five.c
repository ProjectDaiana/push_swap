/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:03:12 by darotche          #+#    #+#             */
/*   Updated: 2023/10/12 17:28:58 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;
	int	size_b;

	size_b = 0;
	min = min_value(*stack_a, lst_size(*stack_a));
	max = max_value(*stack_a, lst_size(*stack_a));
	while (size_b < 2)
	{
		if ((*stack_a)->value == min || (*stack_a)->value == max)
			push(stack_a, stack_b, "pb\n");
		else
			rotate(stack_a, "ra\n");
		size_b = lst_size(*stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	push(stack_b, stack_a, "pa\n");
	if ((*stack_a)->value == max)
		rotate(stack_a, "ra\n");
	push(stack_b, stack_a, "pa\n");
	if ((*stack_a)->value == max)
		rotate(stack_a, "ra\n");
}
