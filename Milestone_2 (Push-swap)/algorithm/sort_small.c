/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:41:56 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/06 16:10:53 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_assign_index(t_stack *stack_a)
{
	t_node	*current;
	t_node	*checker;
	int		count;

	current = stack_a->top;
	while (current != NULL)
	{
		count = 0;
		checker = stack_a->top;
		while (checker != NULL)
		{
			if (checker->value < current->value)
				count++;
			checker = checker->next;
		}
		current->index = count;
		current = current->next;
	}
}

void	sort_two(t_stack *stack_a)
{
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->top->value;       // firsst
	b = stack_a->top->next->value; // Second
	c = stack_a->bottom->value;    // Third
	if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && a > c)
		ra(stack_a);
	else if (b > c && a < c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a > b)
		sa(stack_a);
	else if (b > c)
		rra(stack_a);
}

