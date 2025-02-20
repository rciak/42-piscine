/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C03_ex01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:02:18 by reciak            #+#    #+#             */
/*   Updated: 2025/02/20 21:47:42 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n);

static void	print_testreport(char *s1, char *s2, t_uint n, int ori, int own);

int	main(int argc, char **argv)
{
	int		ori;
	int					own;
	char				*str1;
	char				*str2;
	unsigned int		n;

	if (argc != 1 + 3)
	{
		write(2, "Arguments!\n", 11);
		return (ARGC_WRONG);
	}
	str1 = argv[1];
	str2 = argv[2];
	n = (unsigned int) atoi(argv[3]);

	ori = strncmp(str1, str2, n);
	own = ft_strncmp(str1, str2, n);
	print_testreport(str1, str2, n, ori, own);
	if (own == ori)
		return (NO_ERR);
	else
		return (TEST_FAILED);
}

static void	print_testreport(char *s1, char* s2, t_uint n,  int ori, int own)
{
	printf("---------------------------------------------------------------\n");
	printf("Received: |%s|\n", s1);
	printf("Received: |%s|\n", s2);
	printf("Received: |%d|\n", n);
	printf("strncmp:      %d\n", ori);
	printf("ft_strncmp:   %d\n", own);
	if (own == ori)
		printf("✅\n");
	else
		printf("❌\n");
}

