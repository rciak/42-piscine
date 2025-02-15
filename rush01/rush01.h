/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rene Ciak <rciakAT42Vienna@web.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:42:28 by reciak            #+#    #+#             */
/*   Updated: 2025/02/16 00:13:49 by Rene Ciak        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# define SIZE 4
	
//TODO: CHECK if in accordance to the pdf
//TODO: Transform into enum if allowed by the norm	
# define LOOK_FROM_NORTH 0
# define LOOK_FROM_SOUTH 1
# define LOOK_FROM_WEST 2
# define LOOK_FROM_EAST 3




	typedef struct	s_gen_perms
	{
		char	row_perm[6][SIZE];
		char	col_perm[24][SIZE];
	} t_gen_perms


	int		check_input_validity(char *arg);
	void	set_the_matrix();      //TODO: HowTo make it fitting?
	void	set_row_perm();        //TODO: HowTo make it fitting?
	void	set_col_perm(col_perm);
	//TODO: HowTo make it fitting?
#endif
