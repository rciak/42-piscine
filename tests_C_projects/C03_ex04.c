/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C03_ex04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:26:35 by reciak            #+#    #+#             */
/*   Updated: 2025/02/22 02:25:46 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char		*ft_strstr(char *str, char *to_find);
static void	ft_print_testreport(char *str1, char *str2, char *ori, char *own);

int	main(int argc, char **argv)
{
	char	*haystack;
	char	*needle;
	char	*ori;
	char	*own;

	if (argc != 1 + 2)
	{
		write(2, "Arguments!\n", 11);
		return (ARGC_WRONG);
	}
	haystack = argv[1];
	needle = argv[2];
	ori = strstr(haystack, needle);
	own = ft_strstr(haystack, needle);
	ft_print_testreport(haystack, needle, ori, own);
	if (ori == own)
		return (NO_ERR);
	else
		return (TEST_FAILED);

}

static void ft_print_testreport(char *str1, char* str2, char *ori, char *own)
{
    printf("---------------------------------------------------------------\n");
    printf("Received: |%s|\n", str1);
    printf("Received: |%s|\n", str2);
    printf("strstr:      |%s|\n", ori);
    printf("ft_strstr:   |%s|\n", own);
    if (ori == own)
        printf("✅\n");
    else
        printf("❌\n");
}
