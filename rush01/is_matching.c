/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_matching.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:23:48 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 16:53:51 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		is_matching(char **boundary, char **u_bound)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (boundary[i][j] != u_bound[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
