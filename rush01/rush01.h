/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:42:28 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 20:18:30 by leberton         ###   ########.fr       */
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

typedef struct s_gen_perms
{
	char	row_perm[6][SIZE];
	char	col_perm[24][SIZE];
}	t_perm;

void	store_user_boundaries(char user_boundaries[4][4], char *argv);
void	reset_matrix(char solution[4][4]);
void	set_the_matrix(char the_matrix[4][4][4]);
void	set_row_perm(char row_perm[6][4]);
void	set_col_perm(char col_perm[24][4]);
int		find_solution(char u_bound[4][4], char sol[4][4],
			char matrix[4][4][4], t_perm perm);
void	print_solution(char solution[4][4]);
void	calc_left_border(char *bound_part, char matrix[4][4]);
void	calc_right_border(char *bound_part, char matrix[4][4]);
void	calc_upper_border(char *bound_part, char matrix[4][4]);
void	calc_down_border(char *bound_part, char matrix[4][4]);
void	calc_boundary(char boundary[4][4], char c_permed_matrix[4][4]);
int		is_matching(char boundary[4][4], char u_bound[4][4]);
#endif
