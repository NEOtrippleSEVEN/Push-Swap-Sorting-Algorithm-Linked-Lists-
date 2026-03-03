/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:07:33 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/03 10:47:46 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*old_bottom;
	t_node	*old_top;

	// Guard Condition 
	if(stack_a->size < 2)
		return;
	
	// set old_top = Svae old top inside
	old_bottom = stack_a->bottom;
	old_top = stack_a->top;
	stack_a->top = old_top->next;
	stack_a->bottom->next = old_top;
	old_top->next = NULL;
	stack_a->bottom = old_top;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	t_node	*old_bottom;
	t_node	*old_top;

	if(stack_b->size < 2)
		return;
	old_bottom = stack_b->bottom;
	old_top = stack_b->top;
	stack_b->top = old_top->next;
	stack_b->bottom->next = old_top;
	old_top->next = NULL;
	stack_b->bottom = old_top;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}