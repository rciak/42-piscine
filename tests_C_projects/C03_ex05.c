/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C03_ex05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 02:45:01 by reciak            #+#    #+#             */
/*   Updated: 2025/02/22 02:46:42 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char *ft_strlcat(char *dest, char *src, unsigned int nb);

static void print_testreport(char *str1, char *str2, char *ori, char *own);

int main(int argc, char **argv)
{
    char    *src;
    char    *dest_strlcat;
    char    *dest_ft_strlcat;
    int     nb; 

    if (argc != 1 + 3)
    {   
        write(2, "Arguments!\n", 11);
        return (ARGC_WRONG);
    }   

    src = argv[2];
    dest_strlcat = malloc(strlen(argv[1]) + strlen(src) + 1); 
    dest_ft_strlcat = malloc(strlen(argv[1]) + strlen(src) + 1); 
    strcpy(dest_strlcat, argv[1]);
    strcpy(dest_ft_strlcat, argv[1]);
    nb = atoi(argv[3]);
    strlcat(dest_strlcat, src, nb);
    ft_strlcat(dest_ft_strlcat, src, nb);
    printf("Testreport für received nb: %d\n", nb);
    print_testreport(argv[1], argv[2], dest_strlcat, dest_ft_strlcat);
    if (strcmp(dest_strlcat, dest_ft_strlcat) == 0)
        return (free(dest_strlcat), free(dest_ft_strlcat), NO_ERR);
    else
        return (free(dest_strlcat), free(dest_ft_strlcat), TEST_FAILED);
}

static void print_testreport(char *str1, char* str2, char *ori, char *own)
{
    printf("---------------------------------------------------------------\n");
    printf("Received: |%s|\n", str1);
    printf("Received: |%s|\n", str2);
    printf("strlcat:      |%s|\n", ori);
    printf("ft_strlcat:   |%s|\n", own);
    if (strcmp(ori, own) == 0)
        printf("✅\n");
    else
        printf("❌\n");
}

