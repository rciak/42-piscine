/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:57:58 by reciak            #+#    #+#             */
/*   Updated: 2025/02/22 16:27:56 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

typedef unsigned int t_uint;


enum e_OwnErrorCodes
{
	NO_ERR		= 0,
	ARGC_WRONG	= 1,
	TEST_FAILED	= 2,
};
