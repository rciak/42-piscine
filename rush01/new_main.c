/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:52:51 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 09:49:35 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static st_int	check_input_validity(int argc, char **argv);

int main(int argc, char **argv)
{
	char		user_boundaries[NUM_LOOKING_DIRECTIONS][SIZE];
	char		solution[SIZE][SIZE];
	char		the_matrix[NUM_OF_BASIC_MATRICES][SIZE][SIZE];
	t_gen_perms	gen_perms;

	if (!check_input_validity(argc, argv[1]))
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	store_user_boundaries(user_boundaries, argv[1]);
	clear_solution(solution);
	set_the_matrix(the_matrix);
	set_row_perm(gen_perms.row_perm);
	set_col_perm(gen_perms.col_perm);
	if (!find_solution(solution, the_matrix, gen_perms))
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	print_solution(solution);
	write(1, "\n", 1);
	return (0);
}

static st_int	check_input_validity(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	//TODO: check the string argv[1] ...
}