/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:42:51 by kmurched          #+#    #+#             */
/*   Updated: 2026/03/04 16:31:04 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*

>> Responsibilites <<
|-- Splits arguments
|-- Convert String --> int
|-- manage " 3 2 1 " case
*/

int	ft_is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
static int	get_sign_and_limit(char *str, char **limit, int *i)
{
	int	negative;

	negative = 0;
	if (str[0] == '-')
	{
		negative = 1;
		(*i)++;
	}
	else if (str[0] == '+')
		(*i)++;
	if (negative)
		*limit = "2147483648";
	else
		*limit = "2147483647";
	return (negative);
}
int	ft_is_overflow(char *str)
{
	size_t	size;
	int		i;
	char	*limit;

	i = 0;
	get_sign_and_limit(str, &limit, &i);
	size = ft_strlen(str + i);
	if (size > 10)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] > limit[i])
			return (1);
		if (str[i] < limit[i])
			return (0);
		i++;
	}
	return (0);
}

int	ft_is_duplicate(t_stack *stack_a, int value)
{
	t_node	*current;

	if (!stack_a || !stack_a->top)
		return (0);
	current = stack_a->top;
	while (current != NULL)
	{
		if (current->value == value)
			return (1); // Duplicate found
		current = current->next;
	}
	return (0);
}

void	parse_split(t_stack *stack_a, char *str)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, ' ');
	if (!split)
		ft_error();
	while (split[i] != NULL)
	{
		if (!ft_is_valid_int(split[i]))
			ft_error();
		if (ft_is_overflow(split[i]))
			ft_error();
		if (ft_is_duplicate(stack_a, ft_atoi(split[i])))
			ft_error();
		ft_stack_push(stack_a, ft_atoi(split[i]));
		i++;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	parse_each(t_stack *stack_a, char **argv, int argc)
{
	int	i;

	i = 1; // start argv[1]
	while (i < argc)
	{
		if (!ft_is_valid_int(argv[i]))
		{
			printf("Invalid integer on: %s \n", argv[i]);
			ft_error();
		}
		if (ft_is_overflow(argv[i]))
		{
			printf("Overflow on: %s\n", argv[i]);
			ft_error();
		}
		if (ft_is_duplicate(stack_a, ft_atoi(argv[i])))
		{
			printf("Integer Duplicate on: %s\n", argv[i]);
			ft_error();
		}
		ft_stack_push(stack_a, ft_atoi(argv[i]));
		i++;
	}
}

void	parse_args(t_stack *stack_a, int argc, char **argv)
{
	if (argc == 1)
		return;
	else if (argc == 2)
		parse_split(stack_a, argv[1]);
	else
		parse_each(stack_a, argv, argc);
}
