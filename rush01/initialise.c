/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:01:53 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 15:34:18 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include rush01.h

static void	st_fill(char *line, char *values);

void	reset_matrix(char **solution)
{
	st_fill(solution[0], "0000");
	st_fill(solution[1], "0000");
	st_fill(solution[2], "0000");
	st_fill(solution[3], "0000");
}

void	set_the_matrix(char ***the_matrix)
{
	st_fill(the_matrix[0][0], "1234");
	st_fill(the_matrix[0][1], "2143");
	st_fill(the_matrix[0][2], "2143");
	st_fill(the_matrix[0][3], "4321");
	st_fill(the_matrix[1][0], "1234");
	st_fill(the_matrix[1][1], "2143");
	st_fill(the_matrix[1][2], "3421");
	st_fill(the_matrix[1][3], "4312");
	st_fill(the_matrix[2][0], "1234");
	st_fill(the_matrix[2][1], "2413");
	st_fill(the_matrix[2][2], "3142");
	st_fill(the_matrix[2][3], "4321");
	st_fill(the_matrix[3][0], "1234");
	st_fill(the_matrix[3][1], "2341");
	st_fill(the_matrix[3][2], "3412");
	st_fill(the_matrix[3][3], "4123");
}
void	set_row_perm(char **row_perm)
{
	st_fill(row_perm[0], "0123");
	st_fill(row_perm[1], "0132");
	st_fill(row_perm[2], "0213");
	st_fill(row_perm[3], "0231");
	st_fill(row_perm[4], "0312");
	st_fill(row_perm[5], "0321");
}
void	set_col_perm(char **col_perm)
{
	st_fill(col_perm[0], "0123");
	st_fill(col_perm[1], "0132");
	st_fill(col_perm[2], "0213");
	st_fill(col_perm[3], "0231");
	st_fill(col_perm[4], "0312");
	st_fill(col_perm[5], "0321");
	st_fill(col_perm[6], "1023");
	st_fill(col_perm[7], "1032");
	st_fill(col_perm[8], "1203");
	st_fill(col_perm[9], "1230");
	st_fill(col_perm[10], "1302");
	st_fill(col_perm[11], "1320");
	st_fill(col_perm[12], "2013");
	st_fill(col_perm[13], "2031");
	st_fill(col_perm[14], "2103");
	st_fill(col_perm[15], "2130");
	st_fill(col_perm[16], "2301");
	st_fill(col_perm[17], "2310");
	st_fill(col_perm[18], "3012");
	st_fill(col_perm[19], "3021");
	st_fill(col_perm[20], "3102");
	st_fill(col_perm[21], "3120");
	st_fill(col_perm[22], "3201");
	st_fill(col_perm[23], "3210");
}

static void	st_fill(char *line, char *values)
{
	line[0] = value[0] - '0';
	line[1] = value[1] - '0';
	line[2] = value[2] - '0';
	line[3] = value[3] - '0';
}