/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:33:58 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/04 16:18:36 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*

Responsiobility 
|-- Parse Argument
|-- Validate input 
|-- initialize stack A
|-- Check if already sorted 
|-- Choose Algorithm
|-- Free Everything 

*/

// Flow Exmaple

int main(int argc, char **argv)
{
	// Declare and init two stacks 

	t_stack stack_a;
	t_stack stack_b;

	init_stack(&stack_a, argc, argv);
	ft_stack_init(&stack_b);
	ft_print_stack(&stack_a);

	return 0;
}