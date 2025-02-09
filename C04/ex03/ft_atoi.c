/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:47:44 by reciak            #+#    #+#             */
/*   Updated: 2025/02/09 18:53:49 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// REMARK: atoi is somewhat flawed: it returns 0 on error and does not set errno
// --> Return value 0 has two potential meanings
//     a) Everything worked well and 0 is just a regular return value, e.g by 
//          atoi("-0") 
//     b) An error happened
// Good luck distinguishing between a) and b) when errno is not set by atoi ...
// --> Looking at  atol  might be worthwhile
#include <stdlib.h>       // Def. NULL





int	ft_atoi(char *s)
{
//	Skip white space, see isspace(3)
//  Skip '+-' -> adopt sig
//  if then we have a digit: Start extracting number, else return 0:
	int 		sign_factor;
	long long	nbr;





	st_skip_white_space(&s);
	if (*s == '\0' || !(*s == '+' || *s == '-' || ('0' <= *s && *s <= '9')))
		return 0;
	sign_factor = 1;
	if (*s == '-')
		sign_factor == -1;
	if (*s == '+' || *s == '-')
		s++;
	if (!('0' <= *s && *s <= '9'))
		return 0;
	nbr = 0;
	while ('0' <= *s && *s <= '9')
	{
		nbr = 10 * nbr + (*s - '0'); // ToDo: Check if *s - '0' is converted to long long
		s++;
	}
	nbr = sign_factor * nbr;
	return ((int) nbr);
}