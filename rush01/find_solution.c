/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:06:30 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 18:37:17 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	st_iter_perm(char b_mat[4][4], char u_bnd[4][4], char sol[4][4], t_perm perm);
static void	st_permute_rows(char r_permed_matrix[4][4], char *perm, char b_mat[4][4]);
static void	st_permute_cols(char c_permed_matrix[4][4], char *perm, char r_p_mat[4][4]);
static void	st_set_solution(char sol[4][4], char c_permed[4][4]);

int		find_solution(char u_bound[4][4], char sol[4][4], char matrix[4][4][4], t_perm perm)
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

static int	st_iter_perm(char b_mat[4][4], char u_bnd[4][4], char sol[4][4], t_perm perm)
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
			if (is_matching(boundary, u_bnd))
			{
				st_set_solution(sol, c_permed_matrix);
				return (1);
			}
			k++;
		}
		j++;
	}
	return (0);
}


static void	st_permute_rows(char r_permed_matrix[4][4], char *perm, char b_mat[4][4])
{
	unsigned int	x;

	x = 0;
	while (x < SIZE)
	{
		r_permed_matrix[0][x] = b_mat[(int)perm[0]][x];
		r_permed_matrix[1][x] = b_mat[(int)perm[1]][x];
		r_permed_matrix[2][x] = b_mat[(int)perm[2]][x];
		r_permed_matrix[3][x] = b_mat[(int)perm[3]][x];
		x++;
	}
}

static void	st_permute_cols(char c_permed_matrix[4][4], char *perm, char r_p_mat[4][4])
{
	unsigned int	y;

	y = 0;
	while (y < SIZE)
	{
		c_permed_matrix[y][0] = r_p_mat[y][(int)perm[0]];
		c_permed_matrix[y][1] = r_p_mat[y][(int)perm[1]];
		c_permed_matrix[y][2] = r_p_mat[y][(int)perm[2]];
		c_permed_matrix[y][3] = r_p_mat[y][(int)perm[3]];
		y++;
	}
}

static void	st_set_solution(char sol[4][4], char c_permed[4][4])
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
