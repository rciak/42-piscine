/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C01_ex03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:08:29 by reciak            #+#    #+#             */
/*   Updated: 2025/02/20 17:33:10 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	x;
	int	y;
	int	res_div;
	int	res_mod;

	x = -1;
	y = 4;
	res_div = 0;
	res_mod = 0;
    printf("before calling ft_div_mod(x, y, &res_div, &res_mod) ... \n");
	printf("  x is: %d\n", x);
	printf("  y is: %d\n", y);
	printf("  res_div is: %d\n", res_div);
	printf("  res_mod is: %d\n", res_mod);
	printf("--------------------------------------------------------------------\n");
	ft_div_mod(x, y, &res_div, &res_mod);
	printf("after calling ft_div_mod(x, y, &res_div, &res_mod) ... \n");
	printf("  res_div is: %d\n", res_div);
	printf("  res_mod is: %d\n", res_mod);
}
