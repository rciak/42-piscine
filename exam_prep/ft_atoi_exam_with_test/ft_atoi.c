/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:47:44 by reciak            #+#    #+#             */
/*   Updated: 2025/02/20 14:58:07 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Preliminary REMARK:
// P L E A S E   R E A D  the information written down in  ReadMe.txt !!!

// REMARKS: 
// a) for large digitstrings atoi returns -1, whereas my ft_atoi returns
//    in general somethings else (even more garbage than  atoi )
// b) atoi is somewhat flawed: it returns 0 on error and does not set errno
// --> Return value 0 has two potential meanings
//     a) Everything worked well and 0 is just a regular return value, e.g by 
//          atoi("-0") 
//     b) An error happened
// Good luck distinguishing between a) and b) when errno is not set by atoi ...
// --> Looking at  atol  might be worthwhile
#include <stdlib.h>       // Def. NULL

int	ft_atoi(char *s)
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
