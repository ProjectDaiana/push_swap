/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:43:01 by darotche          #+#    #+#             */
/*   Updated: 2023/10/05 21:19:40 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char *movement)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*tmp;

	n1 = *stack;
	n2 = (*stack)->next;
	tmp = NULL;
	tmp = n1;
	n1 = n2;
	n2 = tmp;
	write(1, movement, 3);
}

void	rotate(t_stack **stack, char	*movement)
{
	t_stack	*head;
	t_stack	*tail;

	head = *stack;
	tail = ft_lstlast(*stack);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	write(1, movement, 3);
}

void	revrotate(t_stack **stack, char *movement)
{
	t_stack	*last;
	t_stack	*head;

	head = *stack;
	last = ft_lstlast(*stack);
	while (head != NULL && head->next != last)
		head = head->next;
	head->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, movement, 4);
}

void	push(t_stack **stack_a, t_stack **stack_b, char *movement)
{
	t_stack	*node_to_push;

	if (stack_a == NULL)
		return ;
	node_to_push = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_b == NULL)
	{
		*stack_b = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *stack_b;
		*stack_b = node_to_push;
	}
	write(1, movement, 3);
}
