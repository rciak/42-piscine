/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:42:28 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 14:37:07 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# define SIZE 4
# define NUM_LOOKING_DIRECTIONS 4
# define NUM_OF_BASIC_MATRICES 4
# define NUM_ROW_PERMS 6
# define NUM_COL_PERMS 24
# define LOOK_FROM_NORTH 0
# define LOOK_FROM_SOUTH 1
# define LOOK_FROM_WEST 2
# define LOOK_FROM_EAST 3

//TODO: CHECK if in accordance to the pdf
//TODO: Transform into enum if allowed by the norm	


typedef struct s_gen_perms
{
	char	row_perm[6][SIZE];
	char	col_perm[24][SIZE];
}	t_perm;

int		check_columns(char *str);
int		check_rows(char *str);
void	store_user_boundaries(char **user_boundaries, char **argv);
void	clear_solution(char **solution);
void	set_the_matrix(char ***the_matrix);
void	set_row_perm(char **row_perm);
void	set_col_perm(char **col_perm);
int		find_solution(char **u_bound, char **sol, char ***matrix, t_perm perm);
void	print_solution(char **solution);
int		calc_boundary(char **boundary, char **c_permed_matrix);
int		is_matching(char **boundary, char **u_bound);
#endif
