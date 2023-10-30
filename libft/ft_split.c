/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:26:42 by ychng             #+#    #+#             */
/*   Updated: 2023/10/31 19:13:14 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	count_no_words(const char *str, const char *delim)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_strchr(delim, str[i]) != NULL)
			i++;
		if (str[i] != '\0')
			word_count++;
		while (str[i] && ft_strchr(delim, str[i]) == NULL)
			i++;
	}
	return (word_count);
}

static size_t	count_word_len(const char *str, const char *delim)
{
	size_t	len;

	len = 0;
	while (str[len] && ft_strchr(delim, str[len]) == NULL)
		len++;
	return (len);
}

static void	insert_word(char **split_str, const char *str, const char *delim)
{
	size_t	i;
	int		j;
	size_t	k;
	size_t	word_len;

	i = 0;
	j = -1;
	while (str[i])
	{
		k = 0;
		while (str[i] && ft_strchr(delim, str[i]) != NULL)
			i++;
		if (str[i] != '\0')
		{
			word_len = count_word_len(str + i, delim);
			split_str[++j] = malloc(sizeof(char) * (word_len + 1));
		}
		while (str[i] && ft_strchr(delim, str[i]) == NULL)
			split_str[j][k++] = str[i++];
	}
	split_str[++j] = 0;
}

char	**ft_split(const char *str, const char *delim)
{
	size_t	word_count;
	char	**split_str;

	if (!str || !delim)
		return (NULL);
	word_count = count_no_words(str, delim);
	split_str = malloc(sizeof(char *) * (word_count + 1));
	if (!split_str)
		return (NULL);
	insert_word(split_str, str, delim);
	return (split_str);
}
