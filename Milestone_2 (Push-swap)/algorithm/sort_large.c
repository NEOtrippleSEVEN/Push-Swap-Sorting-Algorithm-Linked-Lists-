/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:39:04 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/06 16:59:21 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	ft_assign_index(stack_a);
	while (stack_a->size > 3)
		pb(stack_a, stack_b);
	sort_three(stack_a);
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	ft_push_to_b(stack_a, stack_b);
	while (stack_b->size > 0)
	{
		// Find the cheapest node in b
		// Execute it's moves
		// push to a using 'pa'
	}
	// finale roate min to top
}