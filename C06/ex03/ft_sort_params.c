/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:38:34 by reciak            #+#    #+#             */
/*   Updated: 2025/02/26 16:29:12 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>    // write
#include <stddef.h>    // size_t, NULL
#include <bool.h>      // true, false

static bool		st_find_next(char **p_cur_content, int argc, char **argv);
static bool		st_found_successor(char* cur, int argc, char **argv, size_t i);
static	size_t	st_count_occurences(char *cur_content, int argc, char **argv);
static	void	st_print(char *cur_content, size_t occurs);

int	main(int argc, char **argv)
{
	char 	*cur_content;
	size_t	occurs;

	cur_content = NULL;
	index = 0;
	occurs = 0;
	while (st_find_next(&cur_content, argc, argv) != NULL)
	{
		occurs = st_count_occurences(cur_content, argc, argv);
		st_print(cur_content, occurs);
	}
}

static bool	st_find_next(char **p_cur_content, int argc, char **argv)
{
	size_t	i;

	i = 1;
	while (i < argc)
	{
		if (st_found_successor(*p_cur_content, argc, argv, i))
		{
			*p_cur_content = argv[i];
			return (true);
		}
		i++;
	}	
	*p_cur_content = NULL;
	return (false);
}

static	bool st_found_successor(char* cur, int argc, char **argv, size_t i)
{

}

static	size_t	st_count_occurences(char *cur_content, int argc, char **argv)
{

}

static	void	st_print(char *cur_content, size_t occurs)
{

}
