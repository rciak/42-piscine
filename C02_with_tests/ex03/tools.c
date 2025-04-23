/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:00:57 by reciak            #+#    #+#             */
/*   Updated: 2025/02/24 22:48:33 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

bool num_of_actual_args_is(int expected, int argc);
void print_received_arguments(int argc, char **argv);

void print_received_arguments(int argc, char **argv)
{
	int i;

	printf("---------------------------------------------------------------\n");
	printf("Received arguments:\n");
	i = 0;
	while (i < argc)
	{   
		printf("  argv[%d] ", i); 
		if (i < 10) 
		printf(" ");
		printf("== %p  |%s|\n", argv[i], argv[i]);
		i++;	
	}
}

bool num_of_actual_args_is(int expected, int argc)
{
	if (argc != 1 + expected)
	{
		fprintf(stderr, "Wrong number of actual Arguments: ");
		fprintf(stderr, "Expected %d but received %d .\n", expected, argc);
		return (false);
	}
	return (true);
}
