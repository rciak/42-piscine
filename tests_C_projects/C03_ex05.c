/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C03_ex05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 02:45:01 by reciak            #+#    #+#             */
/*   Updated: 2025/02/22 17:33:12 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

static void st_set_data(t_ft_strlcat *data);
static bool	st_num_of_actual_args_is(int expected, int argc);
static void	st_print_received_arguments(int argc, char **argv);
static void print_testreport(char *ori, char *own);

int	main(int argc, char **argv)
{
	t_ft_strlcat	data;

	st_set_data(&data);
	if (!st_num_of_actual_args_is(data.needed_args, argc))
		return (ARGC_WRONG);
	st_print_received_arguments(argc, argv);

	//After here: Still in more ugly first try style
   	char			*src;
    char			*dest_strlcat;
    char			*dest_ft_strlcat;
    int				nb; 

    src = argv[2];
    dest_strlcat = malloc(strlen(argv[1]) + strlen(src) + 1); 
    dest_ft_strlcat = malloc(strlen(argv[1]) + strlen(src) + 1); 
    strcpy(dest_strlcat, argv[1]);
    strcpy(dest_ft_strlcat, argv[1]);
    nb = atoi(argv[3]);
    strlcat(dest_strlcat, src, nb);
    ft_strlcat(dest_ft_strlcat, src, nb);
    printf("Testreport für received nb: %d\n", nb);
    print_testreport(dest_strlcat, dest_ft_strlcat);
    if (strcmp(dest_strlcat, dest_ft_strlcat) == 0)
        return (free(dest_strlcat), free(dest_ft_strlcat), NO_ERR);
    else
        return (free(dest_strlcat), free(dest_ft_strlcat), TEST_FAILED);		
}

static void st_set_data(t_ft_strlcat *data)
{
	data->needed_args = 3;
}

static void st_print_received_arguments(int argc, char **argv)
{
	int	i;

	printf("---------------------------------------------------------------\n");
	printf("Received arguments:\n");
	i = 0;
	while (i < argc)
	{
		printf("  argv[%d] ", i);
		if (i < 10)
			printf(" ");
		printf("== %p  |%s|\n", argv[i], argv[i]);
		i++;
	}
}

static bool st_num_of_actual_args_is(int expected, int argc)
{
	if (argc != 1 + expected)
	{   
		fprintf(stderr, "Wrong number of actual Arguments: ");
		fprintf(stderr, "Expected %d but received %d .\n", expected, argc);
		return (false);
	}
	return (true);
}

static void print_testreport(char *ori, char *own)
{
   printf("strlcat:      |%s|\n", ori);
    printf("ft_strlcat:   |%s|\n", own);
    if (strcmp(ori, own) == 0)
        printf("✅\n");
    else
        printf("❌\n");
}
