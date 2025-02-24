/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C03_ex00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:35:14 by reciak            #+#    #+#             */
/*   Updated: 2025/02/20 17:19:14 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	ft_print_testreport(char *str1, char *str2, int ori, int own);

int			ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	int		ori;
	int		own;
	char	*str1;
	char	*str2;

	if (argc != 1 + 2)
	{
		write(2, "Arguments!\n", 11);
		return (ARGC_WRONG);
	}
	str1 = argv[1];
	str2 = argv[2];
	ori = strcmp(str1, str2);
	own = ft_strcmp(str1, str2);
	ft_print_testreport(str1, str2, ori, own);
	if (own == ori)
		return (NO_ERR);
	else
		return (TEST_FAILED);
}

static void	ft_print_testreport(char *str1, char* str2, int ori, int own)
{
	printf("---------------------------------------------------------------\n");
	printf("Received: |%s|\n", str1);
	printf("Received: |%s|\n", str2);
	printf("strcmp:      %d\n", ori);
	printf("ft_strcmp:   %d\n", own);
	if (own == ori)
		printf("✅\n");
	else
		printf("❌\n");
}
