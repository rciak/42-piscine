/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:56:37 by reciak            #+#    #+#             */
/*   Updated: 2025/02/26 12:09:35 by reciak           ###   ########.fr       */
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
	i = 1;
	while (i < argc)
	{
		len = st_my_strlen(argv[i]);
		write (1, argv[i], len);
		write (1, "\n", 1);
		i++;
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
