/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:45:20 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/04 11:37:58 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
>> Responsibilities <<
|-- Creates Stack nodes
*/

void	init_stack(t_stack *stack_a, int argc, char **argv)
{
	ft_stack_init(stack_a);
	parse_args(stack_a, argc, argv);
}
