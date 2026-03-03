/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:42:51 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/03 16:21:13 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*

>> Responsibilites <<
|-- Splits arguments
|-- Convert String --> int
|-- manage " 3 2 1 " case
*/

void	ft_error(void)
{
}

// Main fucntion called from main.c

void	parse_args(t_stack *stack_a, int argc, char **argv)
{
	/*
	if argc == 1 -> error
	if argc == parse_split(stack_a, argv[1])
	if argc > 2 -> parse_each(stack_a, argv, argc)
	*/
	if (argc == 1)
		ft_error();
	else if (argc == 2)
		parse_split(stack_a, argv[1]);
	else
		parse_each(stack_a, argv, argc);
}

int	parse_split(t_stack *stack_a, char *str)
{
	/*
	split str by ' '
	loop through each piece
		validate each piece
		ft_push_stack onto stack_a
	free the split results suiong ft_free...
	*/
	char **split = ft_split(str, ' ');
	if(!split)
		ft_error();
	while(split!= NULL)
	[
		// Validate == int? 

		// Validate == INT_MAX \+ 1?? 

		// Validate INT_MIN \ -1 ??

		// Validate 
	]	
}
// SHould give me "3" "2" "1";

int	parse_each(t_stack *stack_a, int argc, char **argv)
{
	/*
	loops from argv[1] tp argv[argc-1]
		validate each string
		ft_stack onto stack_a

	*/
}