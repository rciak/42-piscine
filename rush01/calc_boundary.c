/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_boundary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:23:55 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 13:07:43 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rush01.h"

int	calc_boundary(char **boundary, char **c_permed_matrix)
{
	calc_upper_border(boundary[LOOK_FROM_NORTH], c_permed_matrix);
	calc_down_border(boundary[LOOK_FROM_SOUTH], c_permed_matrix);
	calc_left_border(boundary[LOOK_FROM_WEST], c_permed_matrix);
	calc_right_border(boundary[LOOK_FROM_EAST], c_permed_matrix);
}




