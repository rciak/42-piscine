/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C04_ex03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:52:38 by reciak            #+#    #+#             */
/*   Updated: 2025/02/25 13:07:25 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	ft_atoi(char *str);

int main (int argc, char **argv)
{
	int	nbr;
	if (argc != 1 + 1)
	{
		fprintf(stderr, "Error: Wrong number of arguments (1 argument needed)");
		return (0);
	}
	nbr = ft_atoi(argv[1]);
	printf("ft_atoi: |%d|\n", nbr);
	return (0);
}
