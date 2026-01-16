/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:27:32 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/15 22:54:43 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < len - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

static int	countwords(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			word += 1;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word);
}

static int	guaranted_malloc(char **p, size_t len, size_t position)
{
	size_t	i;

	i = 0;
	p[position] = malloc((len + 1) * sizeof(char));
	if (!p[position])
	{
		while (i < position)
			free(p[i++]);
		free(p);
		return (1);
	}
	return (0);
}

static int	fil_string(char **p, const char *s, char c)
{
	size_t	position;
	size_t	start;

	position = 0;
	while (*s)
	{
		start = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			start++;
			s++;
		}
		if (guaranted_malloc(p, start, position))
			return (1);
		ft_strlcpy(p[position], s - start, start + 1);
		position++;
		while (*s == c && *s)
			s++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**p;

	if (s == NULL)
		return (NULL);
	words = countwords(s, c);
	if (words == -1)
		return (NULL);
	p = malloc((words + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	p[words] = NULL;
	if (words == 0)
		return (p);
	if (fil_string(p, s, c))
		return (NULL);
	return (p);
}
