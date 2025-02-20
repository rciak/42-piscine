/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C03_ex02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:06:32 by reciak            #+#    #+#             */
/*   Updated: 2025/02/20 22:45:46 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char *ft_strcat(char *dest, char *src);

static void	print_testreport(char *str1, char *str2, char *ori, char *own);

int	main(int argc, char **argv)
{
	char	*src;
	char	*dest_strcat;
	char	*dest_ft_strcat;

	if (argc != 1 + 2)
	{
		write(2, "Arguments!\n", 11);
		return (ARGC_WRONG);
	}

	src = argv[2];
	dest_strcat = malloc(strlen(argv[1]) + strlen(src) + 1);
	dest_ft_strcat = malloc(strlen(argv[1]) + strlen(src) + 1);
	strcpy(dest_strcat, argv[1]);
	strcpy(dest_ft_strcat, argv[1]);
	strcat(dest_strcat, src);
	strcat(dest_ft_strcat, src);
	print_testreport(argv[1], argv[2], dest_strcat, dest_ft_strcat);
	if (strcmp(dest_strcat, dest_ft_strcat) == 0)
		return (free(dest_strcat), free(dest_ft_strcat), NO_ERR);
	else
		return (free(dest_strcat), free(dest_ft_strcat), TEST_FAILED);
}

static void	print_testreport(char *str1, char* str2, char *ori, char *own)
{
	printf("---------------------------------------------------------------\n");
	printf("Received: |%s|\n", str1);
	printf("Received: |%s|\n", str2);
	printf("strcat:      |%s|\n", ori);
	printf("ft_strcat:   |%s|\n", own);
	if (strcmp(ori, own) == 0)
		printf("✅\n");
	else
		printf("❌\n");
}
