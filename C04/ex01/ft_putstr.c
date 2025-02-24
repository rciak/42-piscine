/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:27:52 by reciak            #+#    #+#             */
/*   Updated: 2025/02/24 23:40:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>    // write
#include <stddef.h>    // size_t

static size_t st_my_strlen(char *str);

void	ft_putstr(char *str)
{
	size_t	len;

	len = st_my_strlen(str);
	write(1, str, len);
}

static size_t st_my_strlen(char *str)
{
	size_t	len;

	len = 0;
	while(str[len])
		len++;
	return(len);
}
