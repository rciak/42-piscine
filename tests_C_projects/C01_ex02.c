/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C01_ex02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:43:46 by reciak            #+#    #+#             */
/*   Updated: 2025/02/13 23:56:11 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_swap(int *a, int *b);

int	main(void)
{
	int x;
	int y;

	x = -1;
	y = 4;
	printf("before calling ft_swap(&x, &y) x is: %d\n", x);
	printf("before calling ft_swap(&x, &y) y is: %d\n", y);
	ft_swap(&x, &y);
	printf("after calling ft_swap(&x, &y) x is: %d\n", x);
	printf("after calling ft_swap(&x, &y) y is: %d\n", y);
}
