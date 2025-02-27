/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:56:25 by reciak            #+#    #+#             */
/*   Updated: 2025/02/27 17:59:15 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>    // malloc

char	*ft_strdup(char *src);

	bold = str;
	care = str;
	
char	*bold;
	char	*care;







char **ft_split(char *str, char *charset)
{
	size_t	num_words;
	size_t	word_len;
	char	**array;
	size_t	i;

	num_words = st_count_words(str, charset);
	array = malloc((num_words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < num_words)
	{
		word_len = st_get_wordlen(word_start, charset);
		array[i] = malloc((wordlen + 1) * sizeof(char));
		if (array[i] == NULL)
		{
			st_free_stuff(array, i);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);	
}
