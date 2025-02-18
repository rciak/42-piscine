/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:33:14 by reciak            #+#    #+#             */
/*   Updated: 2025/02/18 19:11:03 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while(*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest='\0';
	return (start);
}
