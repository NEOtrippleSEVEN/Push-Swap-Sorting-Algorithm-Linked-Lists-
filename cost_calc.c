/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingmurched <kingmurched@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 07:13:30 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/07 13:37:16 by kingmurched      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// For each cost in b -> Bring node to top -> moves target to top of a

// To bring node to top -> rb/ra or rra/rrb
// Cheaper direction depends on the position releative to the median 
if position <= size / 2 -> rotate forward;
if position > size / 2 -> reverse rotate;

int		ft_cost_calc(t_stack *stack_a, t_stack *stack_b){
	t_node *current = stack_b->top;
	t_node *target_position = 0;
	while(current != NULL){
		// Calcuate cost_b (position in b)

		// Calculate target position in a

		// Calculate cost_a (Position of target in a)
		position++;
		current = current->next;
	}
}