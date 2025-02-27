/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C07_ex05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:53:26 by reciak            #+#    #+#             */
/*   Updated: 2025/02/27 21:03:37 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char **ft_split(char *str, char *charset);

int main (int argc, char **argv)
{
	int		i;
	char	**arr;

	if (argc != 1 + 1)
	{
		fprintf(stderr, "Error: Wrong number of arguments (1 argument needed)");
		return (1);
	}
	printf("1. received: |%s|", argv[1]);
	printf("2. received: |%s|", argv[2]);
	arr = ft_split(argv[1], argv[2]);
	i = 0;
	while (arr[i] != NULL)
	{
		printf("arr[%d] : |%s|", i, arr[i]);
		i++;
	}
	return (0);
}

