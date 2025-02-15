/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:39:27 by leberton          #+#    #+#             */
/*   Updated: 2025/02/15 17:47:34 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define SIZE 4

int	check_rows(char *str);
int	check_columns(char *str);

int grid[SIZE][SIZE] = {0};
int	headers[16];


void	print_grid()
{
	int i = 0;
	int j;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			printf("%d", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	complete(char *header)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (header[i * 2] == '4')
		{
			grid[0][i] = 1;
			grid[1][i] = 2;
			grid[2][i] = 3;
			grid[3][i] = 4;
		}
		if (header[i * 2] == '1')
		{
			grid[0][i] = 4;
		}
		i++;
	}
}

int	is_bigger_than_all_previous(int	*seq, int x)
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

void calc_left_border(int *count)
{
	int y = 0;
	int x;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (is_bigger_than_all_previous(grid[y], x))
				count[y]++;
			x++;
		}
		y++;
	}
}

void calc_right_border(int *count)
{
	int y = 0;
	int x;
	int	row[4] = {0};
	while (y < 4)
	{
		row[0] = grid[y][3];
		row[1] = grid[y][2];
		row[2] = grid[y][1];
		row[3] = grid[y][0];
		x = 0;
		while (x < 4)
		{
			if (is_bigger_than_all_previous(row, x))
				count[y]++;
			x++;
		}
		y++;
	}
}


void calc_upper_border(int *count)
{
	int x = 0;
	int y;
	int	column[4] = {0};
	while (x < 4)
	{
		column[0] = grid[0][x];
		column[1] = grid[1][x];
		column[2] = grid[2][x];
		column[3] = grid[3][x];

		y = 0;
		while (y < 4)
		{
			if (is_bigger_than_all_previous(column, y))
				count[x]++;
			y++;
		}
		x++;
	}
}

void calc_down_border(int *count)
{
	int x = 0;
	int y;
	int	column[4] = {0};
	while (x < 4)
	{
		column[0] = grid[3][x];
		column[1] = grid[2][x];
		column[2] = grid[1][x];
		column[3] = grid[0][x];

		y = 0;
		while (y < 4)
		{
			if (is_bigger_than_all_previous(column, y))
				count[x]++;
			y++;
		}
		x++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);

	grid[0][0] = 1;
	grid[0][1] = 2;
	grid[0][2] = 3;
	grid[0][3] = 4;

	grid[2][0] = 2;
	grid[2][1] = 3;
	grid[2][2] = 4;
	grid[2][3] = 1;

	grid[1][0] = 3;
	grid[1][1] = 4;
	grid[1][2] = 1;
	grid[1][3] = 2;

	grid[3][0] = 4;
	grid[3][1] = 1;
	grid[3][2] = 2;
	grid[3][3] = 3;
	int	count[4] = {0};
	calc_upper_border(count);
	for (int i = 0; i < 4; i++)
		printf("Upper border: %d - ", count[i]);
	printf("\n");
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	calc_left_border(count);
	for (int i = 0; i < 4; i++)
		printf("Left border: %d - ", count[i]);
	printf("\n");
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	calc_down_border(count);
	for (int i = 0; i < 4; i++)
		printf("Down border: %d - ", count[i]);
	printf("\n");
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	calc_right_border(count);
	for (int i = 0; i < 4; i++)
		printf("Right border: %d - ", count[i]);
	printf("\n");

	// int	i;
	// int	j;
	//
	// i = 0;
	// while (i < SIZE)
	// {
	// 	j = 0;
	// 	while (j < SIZE)
	// 	{
	// 		grid[i][j] = 1;
	// 		j++;
	// 	}
	// 	i++;
	// }
	if (!check_rows(argv[1]) || !check_columns(argv[1]))
		return (0);
	// complete(argv[1]);
	print_grid();
	return (1);
}
