/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:48:21 by reciak            #+#    #+#             */
/*   Updated: 2025/02/09 12:59:37 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "test.h"

static void	print_testreport(char *str, int ori, int own);
int			ft_atoi(char *str);

int	main(int argc, char **argv)
{
	int		ori;
	int		own;
	char	*str;

	if (argc != 1 + 1)
	{
		write(2, "Arguments!", 10);
		return (ARGC_WRONG);
	}
	str = argv[1];
	ori = atoi(str);
	own = ft_atoi(str);
	print_testreport(str, ori, own);
	if (own == ori)
		return (NO_ERR);
	else
		return (TEST_FAILED);
}

static void	print_testreport(char *str, int ori, int own)
{
	printf("---------------------------------------------------------------\n");
	printf("Received: |%s|\n", str);
	printf("atoi:      %d\n", ori);
	printf("ft_atoi:   %d\n", own);
	if (own == ori)
		printf("✅\n");
	else
		printf("❌\n");
}
