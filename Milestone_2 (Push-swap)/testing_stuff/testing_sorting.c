/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:39:37 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/23 16:35:49 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// Custom comparator 
int 	comp(const void* a, const void* b)
{
	// if 'a' is smaller, positive value will be returned 
	return(*(int*)a - *(int*)b);
}
int main(){
	int arr[] = { 2, 6, 1, 5, 3, 4, 10, 24,22, 1, 34, 20, 155, 2000, 12, 23, 14};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	qsort(arr, n, sizeof(int), comp);	// uses quicksort
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
};

/* 	There are mainly three steps in the algorithm (quick sort)
1. Choose a Pivot:
Select an element from the array as pivot (1st, last, random, or median)
(Alwas choose random element as pivot)

2. Partition the Array: 
Re arrange the array around the pivot. smaller than pivot --> left larger than pivot --> right.

3. Recursivley Call: 
REcursivley apply the same process to the two partionied sub-arrays. (partition #2 etc..).

4. Base Case:
Recursion stopes when there is only one element left in the final sub-array.
*/

typedef struct s_stack
{
	int *array;		// Dynamic Array for element
	int top;		// Index of top element
	int bottom;		// 
	int size;
	
}t_stack;

typedef struct s_push_swap
{
	t_stack stack_a; // Embeded stack A
	t_stack	stack_b; // Embedde Stack B
	
}s_push_swap;

