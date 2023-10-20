/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:02:19 by darotche          #+#    #+#             */
/*   Updated: 2023/10/12 16:36:15 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_argc(argc, argv);
	init_stack(&stack_a, argc, argv);
	if (!is_sorted(stack_a))
	{
		if (lst_size(stack_a) <= 3 && !is_sorted(stack_a))
			sort_three(&stack_a);
		if (lst_size(stack_a) > 3 && lst_size(stack_a) <= 5)
			sort_five (&stack_a, &stack_b);
		if (lst_size(stack_a) > 5)
		{
			indexate(stack_a, lst_size(stack_a));
			radix(&stack_a, &stack_b, max_index(stack_a, lst_size(stack_a)));
		}
	}
	deallocate(&stack_a);
	deallocate(&stack_b);
	return (0);
}
