/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:39:58 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/03 08:07:39 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*	pb ==> push to top of stack_a onto stack_b

1. Check stack_a isn't empty

2. Save the value from stack_a's top

3. Pop it from stack_a

4. Push it onto stack_b

5. Print "pb\n"

*/

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (!stack_a || !stack_a->top)
		return ;
	value = ft_stack_pop(stack_a);
	ft_stack_push(stack_b, value);
	write(1, "pb\n", 3);
}
void	pa(t_stack *stack_b, t_stack *stack_a)
{
	int	value;

	if (!stack_b || !stack_b->top)
		return ;
	value = ft_stack_pop(stack_b);
	ft_stack_push(stack_a, value);
	write(1, "pa\n", 3);
}

