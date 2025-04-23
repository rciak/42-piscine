/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C03_ex03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:13:16 by reciak            #+#    #+#             */
/*   Updated: 2025/02/22 00:09:02 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char *ft_strncat(char *dest, char *src, unsigned int nb);

static void	ft_print_testreport(char *str1, char *str2, char *ori, char *own);

int	main(int argc, char **argv)
{
	char	*src;
	char	*dest_strncat;
	char	*dest_ft_strncat;
	int		nb;

	if (argc != 1 + 3)
	{
		write(2, "Arguments!\n", 11);
		return (ARGC_WRONG);
	}

	src = argv[2];
	dest_strncat = malloc(strlen(argv[1]) + strlen(src) + 1);
	dest_ft_strncat = malloc(strlen(argv[1]) + strlen(src) + 1);
	strcpy(dest_strncat, argv[1]);
	strcpy(dest_ft_strncat, argv[1]);
	nb = atoi(argv[3]);
	strncat(dest_strncat, src, nb);
	ft_strncat(dest_ft_strncat, src, nb);
	printf("Testreport für received nb: %d\n", nb);
	ft_print_testreport(argv[1], argv[2], dest_strncat, dest_ft_strncat);
	if (strcmp(dest_strncat, dest_ft_strncat) == 0)
		return (free(dest_strncat), free(dest_ft_strncat), NO_ERR);
	else
		return (free(dest_strncat), free(dest_ft_strncat), TEST_FAILED);
}

static void	ft_print_testreport(char *str1, char* str2, char *ori, char *own)
{
	printf("---------------------------------------------------------------\n");
	printf("Received: |%s|\n", str1);
	printf("Received: |%s|\n", str2);
	printf("strncat:      |%s|\n", ori);
	printf("ft_strncat:   |%s|\n", own);
	if (strcmp(ori, own) == 0)
		printf("✅\n");
	else
		printf("❌\n");
}

