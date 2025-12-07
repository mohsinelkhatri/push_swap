/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:03:16 by melkhatr          #+#    #+#             */
/*   Updated: 2025/07/24 13:26:35 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	countwords(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	*copy_word(const char *s, char c, int *index_ptr)
{
	int	start;
	int	end;

	while (s[*index_ptr] && s[*index_ptr] == c)
		(*index_ptr)++;
	if (!s[*index_ptr])
		return (NULL);
	start = *index_ptr;
	while (s[*index_ptr] && s[*index_ptr] != c)
		(*index_ptr)++;
	end = *index_ptr;
	return (word_dup(s, start, end));
}

static char	**ft_copy(const char *s, char c, char **split)
{
	int		index;
	size_t	j;
	char	*word;

	index = 0;
	j = 0;
	while (s[index])
	{
		word = copy_word(s, c, &index);
		if (!word)
			break ;
		split[j++] = word;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_copy(s, c, split);
	if (!split)
		return (NULL);
	return (split);
}
