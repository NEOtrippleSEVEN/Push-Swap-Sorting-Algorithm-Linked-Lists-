/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:39:00 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/06 16:12:53 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "libft/libft.h" 

// 	STRUCTS  //
typedef struct s_node 
{
	struct 	s_node *next;
	int 	value;
	int		cost;
	int		index;
	int		above_median;
} t_node;

typedef struct s_stack
{
	t_node *top;				// Index of top element
	t_node *bottom;
	int size;					// Max capacity 
} t_stack;

//------------------PROTOTYPES -- list_utils.c------------------// 
t_node *ft_new_node(int value);
void ft_free_node(t_node *node);

//------------------PROTOTYPES -- stack_utils.c------------------//
void ft_stack_init(t_stack *stack);
void ft_stack_push(t_stack *stack, int value);
int ft_stack_pop(t_stack *stack);

//------------------PROTOTYPES -- Error_free.c ------------------// 
void ft_error(void);

//------------------PROTOTYPES -- Debug directory------------------// 
void ft_print_stack(t_stack *stack);

//------------------PROTOTYPES -- Operations Directory------------------// 
// Push-A		Push-B
void    pa(t_stack *stack_b, t_stack *stack_a);
void    pb(t_stack *stack_a, t_stack *stack_b);

// Swap-A		Swap B 		Swap Both 
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

// Rotate-A			Rotate-B		Roate-Both
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

// Reverse Rotate-A		Reverse Rotate-B 		Reverse Rotate-Both
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);


//------------------PROTOTYPES -- Parsing Dierctory ------------------// 
// PROTOTYPES -- parsing/parse.arg.c
int     ft_is_valid_int(char *str);
int     ft_is_overflow(char *str);
int     ft_is_duplicate(t_stack *stack_a, int value);
void    parse_split(t_stack *stack_a, char *str);
void    parse_each(t_stack *stack_a, char **argv, int argc);
void    parse_args(t_stack *stack_a, int argc, char **argv);

// PROTOTYPES -- parsing/Init Stack.c
void	init_stack(t_stack *stack_a, int agrc, char **argv);



//------------------PROTOTYPES -- Algorithm Dierctory ------------------// 
// sort_small.c
void	ft_assign_index(t_stack *stack_a);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);




#endif
