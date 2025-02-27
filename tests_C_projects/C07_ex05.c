/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C07_ex05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:53:26 by reciak            #+#    #+#             */
/*   Updated: 2025/02/27 21:29:20 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char **ft_split(char *str, char *charset);

int main (int argc, char **argv)
{
	int		i;
	char	**arr;

	if (argc != 1 + 2)
	{
		fprintf(stderr, "Error: Wrong number of arguments (2 needed)\n");
		return (1);
	}
	printf("1. received: |%s|\n", argv[1]);
	printf("2. received: |%s|\n", argv[2]);
	arr = ft_split(argv[1], argv[2]);
	i = 0;
	while (arr[i] != NULL)
	{
		printf("arr[%d] : |%s|\n", i, arr[i]);
		i++;
	}
	return (0);
}

