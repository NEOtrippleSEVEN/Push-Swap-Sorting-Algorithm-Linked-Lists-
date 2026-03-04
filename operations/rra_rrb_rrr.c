/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:50:37 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/03 14:19:52 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*current;

	if (stack_a->size < 2)
		return ;
	// Find secon fot last node
	current = stack_a->top;
	while (current->next != stack_a->bottom)
		current = current->next;
	// Rewire Pointers
	current->next = NULL;
	stack_a->bottom->next = stack_a->top;
	stack_a->top = stack_a->bottom;
	stack_a->bottom = current;
	// Current is now the node just before bottom
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	t_node	*current;

	if (stack_b->size < 2)
		return ;
	current = stack_b->top;
	// Pushing Current to bottom.
	while (current->next != stack_b->bottom)
		current = current->next;
	current->next = NULL;
	// Pointer Re-wiring
	stack_b->bottom->next = stack_b->top;
	stack_b->top = stack_b->bottom;
	stack_b->bottom = current;
	write(1, "rrb\n", 4);
}
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}