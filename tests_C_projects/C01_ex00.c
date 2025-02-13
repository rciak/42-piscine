/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C01_ex00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:15:34 by reciak            #+#    #+#             */
/*   Updated: 2025/02/13 20:16:03 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_ft(int *nbr);

int main (void)
{
	int n;

	n = -3;
	printf("Before calling ft_ft the value of n is:|%d|\n", n);
	ft_ft(&n);
	printf("After calling ft_ft the value of n is: |%d|\n", n);
}
