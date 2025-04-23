/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:54:02 by reciak            #+#    #+#             */
/*   Updated: 2025/02/27 17:56:08 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Warning: the following function will not work if a giant string of length
//   >= SIZE_MAX - 1  is given to it; in practice this should not be a problem.
char	*ft_strdup(char *src)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

