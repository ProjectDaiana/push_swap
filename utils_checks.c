/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:25:48 by darotche          #+#    #+#             */
/*   Updated: 2023/10/12 22:36:55 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argc(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if ((argc == 2 && argv[1][0] == 0) || argv[1][0] == 32)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	if (argc == 2 && (argv[1][0] == '-' || argv[1][0] == '+'))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	return (0);
}

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][0] != '+'
				&& argv[i][0] != '-')
				return (1);
			if (argv[i][j + 1] == '+' || argv[i][j + 1] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_dupl(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*node;

	temp = stack_a;
	while (temp != NULL)
	{
		node = temp->next;
		while (node != NULL)
		{
			if (temp->value == node->value)
			{
				write(2, "Error\n", 6);
				deallocate(&stack_a);
				exit(1);
			}
			node = node->next;
		}
		temp = temp->next;
	}
}

int	is_sorted(t_stack *node)
{
	if (node == NULL)
		return (1);
	while (node->next != NULL)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
