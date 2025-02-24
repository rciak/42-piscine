/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C04_ex00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:39:01 by reciak            #+#    #+#             */
/*   Updated: 2025/02/24 23:20:46 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void st_set_data(t_ft_strlen *data);
void		print_received_arguments(int argc, char **argv);   //see tools.c
bool		num_of_actual_args_is(int expected, int argc);     //see tools.c
int			ft_strlen(char *str);

static void st_set_data(t_ft_strlen *data)
{
	data->needed_args = 1;
	data->ori_name = "strlen";
	data->ori_func = &strlen;
	data->own_name = "ft_strlen";
	data->own_func = &ft_strlen;
}

int	main(int argc, char **argv)
{
	t_ft_strlen	data;

	st_set_data(&data);
	if (!num_of_actual_args_is(data.needed_args, argc))
		return (ARGC_WRONG);
	print_received_arguments(argc, argv);

	//After here: Still more in ugly first try style
	data.ori_reva = data.ori_func(argv[1]);

	data.own_reva = ft_strlen(argv[1]);
	data.own_reva = data.own_func(argv[1]);
	write(1, data.ori_name, strlen(data.ori_name));
    printf("    returned: %lu\n", data.ori_reva);
	write(1, data.own_name, strlen(data.own_name));
    printf(" returned: %d\n", data.own_reva);
    if (data.ori_reva == (unsigned long) data.own_reva)
	{
        printf("✅\n");
		return (NO_ERR);
	}
    else
	{
        printf("❌\n");
		return (TEST_FAILED);
	}
}
