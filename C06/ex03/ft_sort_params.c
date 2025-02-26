/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:38:34 by reciak            #+#    #+#             */
/*   Updated: 2025/02/26 17:38:55 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>    // write
#include <stddef.h>    // size_t, NULL
#include <bool.h>      // true, false

static bool	st_find_next(char **p_cur_content, int argc, char **argv);
static bool	st_found_successor(char* cur, int argc, char **argv, size_t i);

int	main(int argc, char **argv)
{
	char 	*cur_content;
	size_t	i;
	
	cur_content = NULL;
	while (st_find_next(&cur_content, argc, argv))
	{
		i = 1;
		while (i < argc)
		{
			if (ft_strcmp(cur_content, argv[i]) == 0)
			{
				ft_putstr(cur_content);
				ft_putstr("\n");
			}
			i++;
		}
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
	size_t	k;
	char	*candidate;

	candidate = argv[i];
	if (ft_strcmp(cur, candidate) >= 0)
		return (false);
	k = 1;
	while (k < argc)
	{
		if (ft_strcmp(cur, argv[k] < 0) && ft_strcmp(argv[k], candidate) < 0)
			return (false);
		k++;
	}
	return (true);
}

