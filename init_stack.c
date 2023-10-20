/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:40:57 by darotche          #+#    #+#             */
/*   Updated: 2023/10/07 13:34:39 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack_a, int argc, char **argv)
{
	int		i;
	long	nbr;

	i = 1;
	while (argv[i])
	{
		if (check_digits(argc, argv) != 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			write(2, "Error\n", 6);
			deallocate(stack_a);
			exit(1);
		}
		ft_addback(stack_a, nbr);
		i++;
	}
	ft_check_dupl(*stack_a);
}
