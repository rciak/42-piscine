/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:25:29 by reciak            #+#    #+#             */
/*   Updated: 2025/02/20 23:38:15 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while(*ptr)
		ptr++;
	while(*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*dest = '\0';
	return (dest);
}
