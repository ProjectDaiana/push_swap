/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:31:12 by darotche          #+#    #+#             */
/*   Updated: 2023/10/07 12:19:42 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newnode(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->has_i = false;
	new_node->next = NULL;
	return (new_node);
}

void	ft_addback(t_stack **stack_a, int nb)
{
	t_stack	*new;
	t_stack	*temp;

	new = ft_newnode(nb);
	if (!*stack_a)
	{
		*stack_a = new;
		return ;
	}
	temp = *stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	deallocate(t_stack	**stack)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = *stack;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr -> next;
		free(temp);
	}
	*stack = NULL;
}

t_stack	*ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	lst_size(t_stack *stack)
{
	int		i;
	t_stack	*current;

	i = 1;
	if (!stack)
		return (0);
	current = stack;
	while (current->next != 0)
	{
		current = current->next;
		i++;
	}
	return (i);
}
