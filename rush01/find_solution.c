/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:06:30 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 16:53:47 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	st_iter_perm(char **b_mat, char **u_bnd, char **sol, t_pterm perm);
static void	st_permute_rows(char **r_permed_matrix, char *perm, char **b_mat);
static void	st_permute_cols(char **c_permed_matrix, char *perm, char **r_p_mat);
static void	st_set_solution(char **sol, char **c_permed);

int		find_solution(char **u_bound, char **sol, char ***matrix, t_perm perm)
{
	unsigned char	i;
	
	i = 0;
	while (i < NUM_OF_BASIC_MATRICES)
	{
		if (st_iter_perm(matrix[i], u_bound, sol, perm))
			return (1);
		i++;
	}
	return (0);
}

static int	st_iter_perm(char **b_mat, char **u_bnd, char **sol, t_pterm perm)
{
	unsigned char	j;
	unsigned char	k;
	char			r_permed_matrix[SIZE][SIZE];
	char			c_permed_matrix[SIZE][SIZE];
	char			boundary[NUM_LOOKING_DIRECTIONS][SIZE];

	j = 0;
	while (j < NUM_ROW_PERMS)
	{
		st_permute_rows(r_permed_matrix, perm.row_perm[j], b_mat);
		k = 0;
		while (k < NUM_COL_PERMS)
		{
			st_permute_cols(c_permed_matrix, perm.col_perm[k], r_permed_matrix);
			calc_boundary(boundary, c_permed_matrix);
			if (is_matching(boundary, u_bound))
			{
				st_set_solution(sol, c_permed);
				return (1);
			}
			k++;
		}
		j++;
	}
	return (0);
}


static void	st_permute_rows(char **r_permed_matrix, char *perm, char **b_mat)
{
	unsigned int	x;

	x = 0;
	while (x < SIZE)
	{
		r_permed_matrix[0][x] = b_mat[perm[0]][x];
		r_permed_matrix[1][x] = b_mat[perm[1]][x];
		r_permed_matrix[2][x] = b_mat[perm[2]][x];
		r_permed_matrix[3][x] = b_mat[perm[3]][x];
		x++;
	}
}

static void	st_permute_cols(char **c_permed_matrix, char *perm, char **r_p_mat)
{
	unsigned int	y;

	y = 0;
	while (y < SIZE)
	{
		c_permed_matrix[y][0] = r_p_mat[y][perm[0]];
		c_permed_matrix[y][1] = r_p_mat[y][perm[1]];
		c_permed_matrix[y][2] = r_p_mat[y][perm[2]];
		c_permed_matrix[y][3] = r_p_mat[y][perm[3]];
		y++;
	}
}

static void	st_set_solution(char **sol, char **c_permed)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			sol[i][j] = c_permed[i][j];
			j++;
		}
		i++;
	}
}
