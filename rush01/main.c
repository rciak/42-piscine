/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:52:51 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 20:40:35 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

static int	st_check_input_validity(int argc, char *argv);

int	main(int argc, char **argv)
{
	char		user_boundaries[NUM_LOOKING_DIRECTIONS][SIZE];
	char		solution[SIZE][SIZE];
	char		the_matrix[NUM_OF_BASIC_MATRICES][SIZE][SIZE];
	t_perm		gen_perms;

	if (!st_check_input_validity(argc, argv[1]))
	{
		write(1, "Error\n", 6);
		return (2);
	}
	store_user_boundaries(user_boundaries, argv[1]);
	reset_matrix(solution);
	set_the_matrix(the_matrix);
	set_row_perm(gen_perms.row_perm);
	set_col_perm(gen_perms.col_perm);
	if (!find_solution(user_boundaries, solution, the_matrix, gen_perms))
	{
		write(1, "Error\n", 6);
		return (3);
	}
	print_solution(solution);
	return (0);
}

static int	secure_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
		if (i > 40)
			return (i);
	}
	return (i);
}

static int	st_check_input_validity(int argc, char *arg)
{
	int	i;

	if (argc != 2)
		return (0);
	if (secure_strlen(arg) != 31)
		return (0);
	i = 0;
	while (arg[i])
	{
		if (i % 2 == 0 && !(arg[i] >= '1' && arg[i] <= '4'))
			return (0);
		if (i % 2 == 1 && (arg[i] != ' '))
			return (0);
		i++;
	}
	return (1);
}
