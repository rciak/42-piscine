/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:17:04 by reciak            #+#    #+#             */
/*   Updated: 2025/02/09 10:27:01 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
int		checkargs(int x_max, int y_max);
void	construct_line(int y, int y_max, int x_max);
void	print_line(char *cur_line_symbols, int x_max);
void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	j;

	if (! checkargs(x, y))
		return ;
	j = 1;
	while (j <= y)
	{
		construct_line (j, y, x);
		j++;
	}
}

int	checkargs(int x_max, int y_max)
{
	if (x_max <= -1 || y_max <= -1)
	{
		write(2, "No negative input\n", 18);
		return (0);
	}
	else if (x_max == 0 || y_max == 0)
	{
		write(2, "Nothing to see here\n", 20);
		return (0);
	}
	else
		return (1);
}

void	construct_line(int y, int y_max, int x_max)
{
	char	*chars_top;
	char	*chars_mid;
	char	*chars_end;

	chars_top = "ABC";
	chars_mid = "B B";
	chars_end = "CBA";
	if (y == 1)
		print_line(chars_top, x_max);
	else if (y == y_max)
		print_line(chars_end, x_max);
	else
		print_line(chars_mid, x_max);
}

void	print_line(char *cur_line_symbols, int x_max)
{
	int		x;
	char	current_char;

	x = 1;
	while (x <= x_max)
	{
		if (x == 1)
			current_char = cur_line_symbols[0];
		else if (x == x_max)
			current_char = cur_line_symbols[2];
		else
			current_char = cur_line_symbols[1];
		ft_putchar(current_char);
		x++;
	}
	ft_putchar('\n');
}
