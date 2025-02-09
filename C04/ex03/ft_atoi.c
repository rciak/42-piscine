/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:47:44 by reciak            #+#    #+#             */
/*   Updated: 2025/02/09 12:55:40 by reciak           ###   ########.fr       */
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
	str = NULL;
	return (0);
}
