/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_typdef_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:17:15 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/23 17:01:57 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

typedef struct Students{	
	int age;
	char *name[50];
	float grade;
}Students;

int main(){
	
	
	Students s1;
	Students s2;

	s1.age = 23;
	s2.age = 22;
	snprintf(s1.name, sizeof(s1.name), "Ahamd");
	snprintf(s2.name, sizeof(s2.name), "Mohammad");
	s1.grade = 22.6;
	s2.grade = 20.3;


	printf("Student 1\n Name:%s\n Age: %d\n Grade: %f\n\n", s1.name, s1.age, s1.grade);
	printf("Student 2\n Name: %s\n Age: %d\n Grade: %f\n", s2.name, s2.age, s2.grade);
	return 0;
}