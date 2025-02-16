/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_boundary_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:57:32 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 13:20:25 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	st_is_bigger_than_all_previous(int	*seq, int x);

void calc_left_border(char *bound_part, char **matrix)
{
	int y;
	int x;

	y = 0;
	bound_part[0] = 0;
	bound_part[1] = 0;
	bound_part[2] = 0;
	bound_part[3] = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (st_is_bigger_than_all_previous(matrix[y], x))
				bound_part[y]++;
			x++;
		}
		y++;
	}
}

void calc_right_border(char *bound_part, char **matrix)
{
	int y;
	int x;
	int	row[4];

	y = 0;
	bound_part[0] = 0;
	bound_part[1] = 0;
	bound_part[2] = 0;
	bound_part[3] = 0;
	while (y < 4)
	{
		row[0] = matrix[y][3];
		row[1] = matrix[y][2];
		row[2] = matrix[y][1];
		row[3] = matrix[y][0];
		x = 0;
		while (x < 4)
		{
			if (st_is_bigger_than_all_previous(row, x))
				bound_part[y]++;
			x++;
		}
		y++;
	}
}


void calc_upper_border(char *bound_part, char **matrix)
{
	int x;
	int y;
	int	column[4];

	x = 0;
	bound_part[0] = 0;
	bound_part[1] = 0;
	bound_part[2] = 0;
	bound_part[3] = 0;
	while (x < 4)
	{
		column[0] = matrix[0][x];
		column[1] = matrix[1][x];
		column[2] = matrix[2][x];
		column[3] = matrix[3][x];

		y = 0;
		while (y < 4)
		{
			if (st_is_bigger_than_all_previous(column, y))
				bound_part[x]++;
			y++;
		}
		x++;
	}
}

void calc_down_border(char *bound_part, char **matrix)
{
	int x;
	int y;
	int	column[4];

	x = 0;
	bound_part[0] = 0;
	bound_part[1] = 0;
	bound_part[2] = 0;
	bound_part[3] = 0;
	while (x < 4)
	{
		column[0] = matrix[3][x];
		column[1] = matrix[2][x];
		column[2] = matrix[1][x];
		column[3] = matrix[0][x];
		y = 0;
		while (y < 4)
		{
			if (st_is_bigger_than_all_previous(column, y))
				bound_part[x]++;
			y++;
		}
		x++;
	}
}

static int	st_is_bigger_than_all_previous(int	*seq, int x)
{
	if (x == 0)
		return (1);
	else if (x == 1 && seq[x] > seq[0])
		return (1);
	else if (x == 2 && seq[x] > seq[1] && seq[x] > seq[0])
		return (1);
	else if (x == 3 && seq[x] > seq[2] && seq[x] > seq[1] && seq[x] > seq[0])
		return (1);
	return (0);
}
