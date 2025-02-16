/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_boundary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:23:55 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 17:41:35 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	calc_boundary(char boundary[4][4], char c_permed_matrix[4][4])
{
	calc_upper_border(boundary[LOOK_FROM_NORTH], c_permed_matrix);
	calc_down_border(boundary[LOOK_FROM_SOUTH], c_permed_matrix);
	calc_left_border(boundary[LOOK_FROM_WEST], c_permed_matrix);
	calc_right_border(boundary[LOOK_FROM_EAST], c_permed_matrix);
}

void	store_user_boundaries(char user_boundaries[4][4], char *argv)
{
	user_boundaries[LOOK_FROM_NORTH][0] = argv[0];
	user_boundaries[LOOK_FROM_NORTH][1] = argv[2];
	user_boundaries[LOOK_FROM_NORTH][2] = argv[4];
	user_boundaries[LOOK_FROM_NORTH][3] = argv[6];
	user_boundaries[LOOK_FROM_SOUTH][0] = argv[8];
	user_boundaries[LOOK_FROM_SOUTH][1] = argv[10];
	user_boundaries[LOOK_FROM_SOUTH][2] = argv[12];
	user_boundaries[LOOK_FROM_SOUTH][3] = argv[14];
	user_boundaries[LOOK_FROM_WEST][0] = argv[16];
	user_boundaries[LOOK_FROM_WEST][1] = argv[18];
	user_boundaries[LOOK_FROM_WEST][2] = argv[20];
	user_boundaries[LOOK_FROM_WEST][3] = argv[22];
	user_boundaries[LOOK_FROM_EAST][0] = argv[24];
	user_boundaries[LOOK_FROM_EAST][1] = argv[26];
	user_boundaries[LOOK_FROM_EAST][2] = argv[28];
	user_boundaries[LOOK_FROM_EAST][3] = argv[30];
}



