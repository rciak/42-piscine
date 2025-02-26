/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_second_bonus_part.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:09:11 by reciak            #+#    #+#             */
/*   Updated: 2025/02/09 23:24:59 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
int		my_atoi(char *str);

// Remark: The seemingly missing validity check of the two input strings
//    argv[1] and argv[2] is done indirectly: my_atoi  returns 0 in case of
//    an invalid input string like "p137" (just like the original atoi).
//    Therefore the check
//        x <= 0 || y <= 0  
//    is sufficient to catch nonsense input strings.
int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc != 1 + 2)
	{
		write (2, "Error: Wrong number of arguments.", 33);
		write (2, " Try two positive integers as parameters.\n", 42);
		return (-1);
	}
	x = my_atoi(argv[1]);
	y = my_atoi(argv[2]);
	if (x <= 0 || y <= 0)
	{
		write (2, "Error: Try two positive integers as parameters.\n", 48);
		return (-1);
	}
	rush(x, y);
	return (0);
}

int	my_atoi(char *s)
{
	int			sign_factor;
	long long	nbr;

	if (s == NULL)
		return (0);
	while (*s == ' ' || *s == '\n' || *s == '\t'
		|| *s == '\v' || *s == '\f' || *s == '\r' )
		s++;
	if (*s == '\0' || !(*s == '+' || *s == '-' || ('0' <= *s && *s <= '9')))
		return (0);
	sign_factor = 1;
	if (*s == '-')
		sign_factor = -1;
	if (*s == '+' || *s == '-')
		s++;
	if (!('0' <= *s && *s <= '9'))
		return (0);
	nbr = 0;
	while ('0' <= *s && *s <= '9')
	{
		nbr = 10 * nbr + (*s - '0');
		s++;
	}
	nbr = sign_factor * nbr;
	return ((int) nbr);
}
