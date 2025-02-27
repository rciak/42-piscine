/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:56:25 by reciak            #+#    #+#             */
/*   Updated: 2025/02/27 21:22:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>    // malloc
#include <stdbool.h>   // true, false


static size_t	st_count_words(char *str, char *charset);
static size_t	st_is_sep(char c, char* charset);
static size_t	st_word_len(char *str, char* charset);
char			*ft_strncpy(char *dest, char *src, unsigned int n);

// Since we are not allowed to use free the stuff is somewhat flawed 
// from the very beginning if malloc fails..., cf. below
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
		while (st_is_sep(*str, charset))
			str++;
		word_len = st_word_len(str, charset);
		array[i] = malloc((word_len + 1) * sizeof(char));
		ft_strncpy(array[i], str, word_len + 1);
		if (array[i] == NULL)
			return (array);
		while (!st_is_sep(*str, charset) && *str != '\0')
			str++;
		i++;
	}
	array[i] = NULL;
	return (array);	
}

static size_t	st_count_words(char *str, char *charset)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (st_is_sep(*str, charset))
			str++;
		while (!st_is_sep(*str, charset) && *str != '\0')
			str++;
		count++;
	}
	return (count);
}

static size_t	st_is_sep(char c, char* charset)
{
	while(*charset)
	{
		if (c == *charset)
			return (true);
		charset++;
	}
	return (false);
}

static size_t	st_word_len(char *str, char *charset)
{
	size_t	count;

	count = 0;
	while (!st_is_sep(str[count], charset) && str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*start;
	unsigned int	i;

	start = dest;
	i = 0;
	while (*src && i < n)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	return (start);
}
// REMARK: Normally that functions should be implemented, but 
//    free is not allowed...
// --> Checkout  6efec471611bc49f77cd87e3353b334e5adf0154
//     for a drafted version where it was intended to call  st_free_heap
/*
static void		st_free_heap(char **array, i)
{
	while (i > 0)
	{
		i--;
		free()
	}
	
}
*/
