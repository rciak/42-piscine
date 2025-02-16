/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:52:51 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 16:17:56 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	st_check_input_validity(int argc, char **argv);

int main(int argc, char **argv)
{
	char		user_boundaries[NUM_LOOKING_DIRECTIONS][SIZE];
	char		solution[SIZE][SIZE];
	char		the_matrix[NUM_OF_BASIC_MATRICES][SIZE][SIZE];
	t_perm	gen_perms;

	if (!st_check_input_validity(argc, argv[1]))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	store_user_boundaries(user_boundaries, argv[1]);
	reset_matrix(solution);
	set_the_matrix(the_matrix);
	set_row_perm(gen_perms.row_perm);
	set_col_perm(gen_perms.col_perm);
	if (!find_solution(user_boundaries, solution, the_matrix, gen_perms))
	{
		write(2, "Error\n", 6);
		return (-2);
	}
	print_solution(solution);
	write(1, "\n", 1);
	return (0);
}

static int	st_check_input_validity(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	if (!check_columns(argv[1]) || !check_rows(argv[1]))
		return (-1);
	return (1);
}
