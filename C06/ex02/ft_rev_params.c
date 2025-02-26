/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:13:14 by reciak            #+#    #+#             */
/*   Updated: 2025/02/26 12:21:15 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>    // write
#include <stddef.h>    // size_t

static size_t	st_my_strlen(char *str);

int	main(int argc, char **argv)
{
	int		i;
	size_t	len;

	if (argc == 1 + 0)
		return (0);
	i = argc - 1;
	while (i > 0)
	{
		len = st_my_strlen(argv[i]);
		write (1, argv[i], len);
		write (1, "\n", 1);
		i--;
	}
}

static size_t	st_my_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
