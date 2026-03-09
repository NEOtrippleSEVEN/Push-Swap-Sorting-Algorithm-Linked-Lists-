/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingmurched <kingmurched@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 12:22:05 by kingmurched       #+#    #+#             */
/*   Updated: 2026/03/07 12:58:16 by kingmurched      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
For each node in 'b', find where it belongs in 'a'.

The Rule:
	Find the largest value in 'a' that is still smaller than b_node->value 
	that node in 'a' is the target. 
*/

/* 
Example:

stack_a: [6][3][1] 		(indexes: 2, 1, 0)
stack_b: [7][2][4]

node 7 -> Largest in 'a' smaller than 7 -> 6 -> target node is 6
node 2 -> Largest in 'a' smaller than 2 -> 1 -> target node is 1
node 4 -> Largest in 'a' smaller than 4 -> 3 -> target node is 3

*/

t_node	*ft_find_max(t_stack *stack){
	
	t_node *max = stack->top;
	t_node *current = stack->top;
	
	while(current != NULL){
		if(current->value > max->value)
			max = current; 
		current = current->next;
	}	
	return max;
}

t_node 		*ft_target_position(t_stack *stack_a, t_node *b_node){

	t_node *target = NULL;
	t_node *current = stack_a->top;
	
	while(current != NULL){
		if (current->value < b_node->value){
			if(target == NULL || current->value > target->value)
				target = current;
		}	
		current = current->next;
	}
	if(target == NULL)
		target = ft_find_max(stack_a);
	return target;
}