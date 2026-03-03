/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:27:57 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/03 09:20:59 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}
void	ft_stack_push(t_stack *stack, int value)
{
	t_node	*node;

	// Create a new node
	node = ft_new_node(value);
	if (!node)
		return ;
	/* Emoty Stack */
	if (stack->top == NULL)
	{
		// Handle the case where stack already has the code in it.
		node->next = NULL;
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		// Update Top, Bottom, Size.
		node->next = stack->top;
		stack->top = node;
	}
	stack->size++;
}

int	ft_stack_pop(t_stack *stack)
{
	int		value;
	t_node	*next;

	if (!stack || !stack->top)
		return (-1);
	// save value of top;
	value = stack->top->value;
	// save the next pointer;
	next = stack->top->next;
	// free the top node
	ft_free_node(stack->top);
	stack->top = NULL;
	// Update top into = value so you can return it.
	stack->top = next;
	stack->size--;
	if (stack->size == 0)
		stack->bottom = NULL;
	return (value);
}
