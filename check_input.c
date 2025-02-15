/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:56:01 by leberton          #+#    #+#             */
/*   Updated: 2025/02/15 16:48:55 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_columns(char *str)
{
	int current = 0;
	int found_ones = 0;
	int	found_fours = 0;
	while (current <= 6)
	{
		if (str[current] == '4' && str[current + 8] != '1')
		{
			printf("Found %c in front of a 4", str[current + 8]);
			return (0);
		}
		if (str[current + 8] == '4' && str[current] != '1')
		{
			printf("Found %c in front of a 4", str[current]);
			return (0);
		}
		if (str[current] == '1')
		{
			found_ones++;
			if (found_ones > 1)
			{
				printf("Found more than one 1 in the column");
				return (0);
			}
		}
		if (str[current] == '4')
		{
			found_fours++;
			if (found_fours > 1)
			{
				printf("Found more than one four in the column");
				return (0);
			}
		}
		current += 2;
	}
	return (1);
}

int	check_rows(char *str)
{
	int current = 16;
	int found_ones = 0;
	int	found_fours = 0;
	while (current <= 22)
	{
		if (str[current] == '4' && str[current + 8] != '1')
		{
			printf("Found %c in front of a 4", str[current + 8]);
			return (0);
		}
		if (str[current + 8] == '4' && str[current] != '1')
		{
			printf("Found %c in front of a 4", str[current]);
			return (0);
		}
		if (str[current] == '1')
		{
			found_ones++;
			if (found_ones > 1)
			{
				printf("Found more than one 1 in the row");
				return (0);
			}
		}
		if (str[current] == '4')
		{
			found_fours++;
			if (found_fours > 1)
			{
				printf("Found more than one four in the row");
				return (0);
			}
		}
		current += 2;
	}
	return (1);
}
