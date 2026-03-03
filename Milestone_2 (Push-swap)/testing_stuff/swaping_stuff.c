/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 09:24:39 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/24 09:42:06 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Swaps
{
	int	a;
	int	b;
}		Swaps;

void	swap(int *a, int *b)
{
	int	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	Swaps p1;
	Swaps p2;

	p1.a;
	p1.b;
	p2.a;
	p2.b;

	swap(&p1.a, &p1.b);
	swap(&p2.a, &p2.b);

	printf("");
	return (0);
}