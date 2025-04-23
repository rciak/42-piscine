/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C04_ex01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:35:37 by reciak            #+#    #+#             */
/*   Updated: 2025/02/24 23:49:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	st_set_data(t_ft_putstr *data);
void		print_received_arguments(int argc, char **argv);   //see tools.c
bool		num_of_actual_args_is(int expected, int argc);     //see tools.c

int			ft_putstr(char *str);

static void	st_set_data(t_ft_putstr *data)
{
	data->needed_args = 1;
	data->own_name = "ft_putstr";
	data->own_func = &ft_putstr;
}

int main(int argc, char **argv)
{
	t_ft_putstr data;

	st_set_data(&data);
	if (!num_of_actual_args_is(data.needed_args, argc))
		return (ARGC_WRONG);
	print_received_arguments(argc, argv);

	//After here: Still more in ugly first try style
	data.own_func(argv[1]);
}
