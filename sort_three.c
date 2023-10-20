/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:57:31 by darotche          #+#    #+#             */
/*   Updated: 2023/10/06 18:44:23 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	val;
	int	next;
	int	last;

	val = (*stack_a)->value;
	next = (*stack_a)->next->value;
	last = ft_lstlast(*stack_a)->value;
	if (*stack_a == NULL)
		return ;
	if (val < next && val < last)
	{
		revrotate(stack_a, "rra\n");
		swap(stack_a, "sa\n");
	}
	else if (val > next && val > last)
	{
		rotate(stack_a, "ra\n");
		if (!is_sorted(*stack_a))
			swap(&*stack_a, "sa\n");
	}
	else if (val > next && val < last)
		swap(stack_a, "sa\n");
	else if (val < next && val > last)
		revrotate(stack_a, "rra\n");
}
