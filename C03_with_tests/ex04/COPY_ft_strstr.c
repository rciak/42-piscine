/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:24:41 by reciak            #+#    #+#             */
/*   Updated: 2025/02/22 02:30:27 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

static bool	st_is_match(char *cur, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	while (*str)
	{
		if (st_is_match(str, to_find))
			return (str);
		str++;
	}
	return (NULL);
}

static bool	st_is_match(char *cur, char *to_find)
{
	while (*to_find)
	{
		if (*cur != *to_find || *cur == '\0')
			return (false);
		cur++;
		to_find++;
	}
	return (true);
}
