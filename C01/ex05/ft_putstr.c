/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:53:48 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 23:26:29 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	my_strlen(char *str);

void	ft_putstr(char *str)
{
	size_t	len;

	if (str == NULL)
		return ;
	len = my_strlen(str);
	write(1, str, len);
}

static size_t	my_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
