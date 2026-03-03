/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:30:22 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/03 08:07:35 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		printf("Value: %d \n", current->value);
		current = current->next;
	}
}
