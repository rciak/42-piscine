/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:47:44 by reciak            #+#    #+#             */
/*   Updated: 2025/02/09 17:35:01 by Rene Ciak        ###   ########.fr       */
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


int	ft_atoi(char *str)
{
//	Skip white space, see isspace(3)
//  Skip '+-' -> adopt sig
//  if then we have a digit: Start extracting number, else return 0:


	while (*str != '\0' )
	str = NULL;
	return (0);
}
