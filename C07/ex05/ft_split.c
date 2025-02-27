/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:56:25 by reciak            #+#    #+#             */
/*   Updated: 2025/02/27 18:58:07 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>    // malloc

static size_t	st_count_words(char *str, char *charset);
static size_t	st_is_sep(char *str, char* charset);
static size_t	st_word_len(char *str, char* charset);
static void		st_free_heap(char **array, i);

char **ft_split(char *str, char *charset)
{
	size_t	i;
	size_t	num_words;
	char	**array;
	size_t	word_len;

	num_words = st_count_words(str, charset);
	array = malloc((num_words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < num_words)
	{
		while (st_is_sep(str, charset))
			str++;
		word_len = st_word_len(str, charset);
		array[i] = malloc((word_len + 1) * sizeof(char));
		if (array[i] == NULL)
		{
			st_free_heap(array, i);
			return (NULL);
		}
		while (!st_is_sep(str, charset) && *str != '\0')
			str++;
		i++;
	}
	array[i] = NULL;
	return (array);	
}

static size_t	st_count_words(char *str, char *charset)
{

}

static size_t	st_is_sep(char *str, char* charset);
{

}


static size_t	st_word_len(char *str, char* charset)
{

}

static void		st_free_heap(char **array, i)
{

}
