/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:38:34 by reciak            #+#    #+#             */
/*   Updated: 2025/02/26 18:19:46 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>    // write
#include <stddef.h>    // size_t, NULL
#include <stdbool.h>   // true, false

static int	st_ft_strcmp(char *s1, char *s2);
static void	st_var_putstr(char *str);
static bool	st_find_next(char **p_cur_content, int argc, char **argv);
static bool	st_found_successor(char *cur, int argc, char **argv, size_t i);

int	main(int argc, char **argv)
{
	char	*cur_content;
	int		i;

	if (argc < 1 + 1)
		return (0);
	cur_content = argv[1];
	while (st_find_next(&cur_content, argc, argv))
	{
		i = 1;
		while (i < argc)
		{
			if (st_ft_strcmp(cur_content, argv[i]) == 0)
			{
				st_var_putstr(cur_content);
				st_var_putstr("\n");
			}
			i++;
		}
	}
}

static bool	st_find_next(char **p_cur_content, int argc, char **argv)
{
	int	i;

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

static bool	st_found_successor(char *cur, int argc, char **argv, size_t i)
{
	int		k;
	char	*candid;

	candid = argv[i];
	if (st_ft_strcmp(cur, candid) >= 0)
		return (false);
	k = 1;
	while (k < argc)
	{
		if (st_ft_strcmp(cur, argv[k]) < 0 && st_ft_strcmp(argv[k], candid) < 0)
			return (false);
		k++;
	}
	return (true);
}

int	st_ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	else
		return (0);
}

void	st_var_putstr(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}
