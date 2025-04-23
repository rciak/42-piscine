/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:57:58 by reciak            #+#    #+#             */
/*   Updated: 2025/02/24 23:50:35 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <stdbool.h>
# include <stdlib.h>
# include <bsd/string.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

void	print_received_arguments(int argc, char **argv);
void	print_testreport(char *ori, char *own);

typedef unsigned int	t_uint;
typedef	unsigned long	t_ulong;

//C04, ex01
typedef struct	s_ft_putstr
{
	int			needed_args;
	const char	*own_name;
	int			(*own_func)(char *);
}				t_ft_putstr;

//C04, ex00
typedef struct	s_ft_strlen
{
	int			needed_args;
	const char	*ori_name;
	const char	*own_name;
	t_ulong		ori_reva;
	int			own_reva;
	t_ulong		(*ori_func)(const char *);
	int			(*own_func)(char *);
}				t_ft_strlen;

//C03, ex05
typedef struct	s_ft_strlcat
{
	int needed_args;
	
}				t_ft_strlcat;


enum e_OwnErrorCodes
{
	NO_ERR		= 0,
	ARGC_WRONG	= 1,
	TEST_FAILED	= 2,
};
#endif
