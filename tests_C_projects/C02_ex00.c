/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C02_ex00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:34:25 by reciak            #+#    #+#             */
/*   Updated: 2025/02/18 19:18:38 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{	
	char	copy_with_too_less_mem[5];
	char	copy[6 + 1];
	char	*ori;

	ori="Hello!";
	printf("ori: %p |%s|\n", ori, ori);
	printf("--------------------------------------------\n");
	printf("calling ft_strcpy(copy, ori)\n");
	ft_strcpy(copy, ori);
	printf("   ori:  %p |%s|\n", ori, ori);
	printf("   copy: %p |%s|\n", copy, copy);
	printf("--------------------------------------------\n");
	printf("calling ft_strcpy(copy_with_too_less_mem, ori)\n");
	ft_strcpy(copy_with_too_less_mem, ori);
	printf("   ori:  %p |%s|\n", ori, ori);
	printf("   copy: %p |%s|\n", copy, copy);
	printf("   copy: %p |%s|\n", copy_with_too_less_mem, copy_with_too_less_mem);
}
