/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 02:32:32 by reciak            #+#    #+#             */
/*   Updated: 2025/02/23 17:22:09 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static unsigned int	my_strlen(char *str);

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	ori_len_dest;
	unsigned int	len_src;

	ori_len_dest = my_strlen(dest);
	len_src = my_strlen(src);
	while (*dest && size > 1)
	{
		dest++;
		size--;
	}
	if (size <= 1)
		return (ori_len_dest + len_src);
	while (*src && size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = '\0';
	return (ori_len_dest + len_src);
}

static unsigned int	my_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
