/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:33:58 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/03 09:53:10 by kmurched         ###   ########.fr       */
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

int main()
{
	// Declare and init two stacks 

	t_stack stack_a;
	t_stack stack_b;

	ft_stack_init(&stack_a);
	ft_stack_init(&stack_b);

	// Push a few Hardcoded values onto stack_a
	ft_stack_push(&stack_a, 1);
	ft_stack_push(&stack_a, 32);
	ft_stack_push(&stack_a, 11);
	ft_stack_push(&stack_a, 2);
	ft_stack_push(&stack_a, 30);
	ft_stack_push(&stack_a, 110);

	// Print stack_a to verify
	ft_print_stack(&stack_a);
	
	// Pop a value and print it to verify
	int popped = ft_stack_pop(&stack_a);
	printf("Popped value: %d\n", popped);
	ft_print_stack(&stack_a);



	printf("----------------------------- Swap Testing ----------------------");
	
	printf("--- After pa ---\n");
	pa(&stack_b, &stack_a);
	ft_print_stack(&stack_a);

	
	printf("--- After pb ---\n");
	pb(&stack_a, &stack_b);
	ft_print_stack(&stack_b);
	
	printf("Init done. size: %d\n", stack_a.size);  // should print 0
	printf("----------------------------- Rotate Testing ----------------------");
	return 0;
}