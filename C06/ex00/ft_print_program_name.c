/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:41:40 by reciak            #+#    #+#             */
/*   Updated: 2025/02/26 11:46:50 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>    // write
#include <stddef.h>    // size_t

static size_t	st_my_strlen(char *str);

int	main(int argc, char **argv)
{
	size_t	len;

	len = st_my_strlen(argv[0]);
	write (1, argv[0], len);
}

static size_t	st_my_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
