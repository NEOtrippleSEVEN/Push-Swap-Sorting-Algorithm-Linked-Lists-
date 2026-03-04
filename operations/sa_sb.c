/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:50:36 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/03 08:07:48 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* sa_sb.c
Responsibility:
|-- sa: Swap top 2 elements of stack_a
|-- sb: Swap top 2 elements of stack_b
|-- ss: sa and sb at the same time
*/

void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->top->value;
	stack_a->top->value = stack_a->top->next->value;
	stack_a->top->next->value = temp;
	write(1, "sa\n", 3);
}
void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->top->value;
	stack_b->top->value = stack_b->top->next->value;
	stack_b->top->next->value = temp;
	write(1, "sb\n", 3);
}
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
