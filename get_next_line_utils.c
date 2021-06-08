/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:14:01 by aarts             #+#    #+#             */
/*   Updated: 2021/06/08 14:35:53 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_chr(char *s, int c)
{
	char	*pointer;

	pointer = (char *)s;
	while (*pointer)
	{
		if (*pointer == (char) c)
			return (pointer);
		pointer++;
	}
	if (*pointer == 0 && (char) c == 0)
		return (pointer);
	return (NULL);
}

static size_t	str_len(char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*strl_cpy(char *src, size_t dstsize)
{
	char	*dst;
	size_t	i;

	dst = malloc(sizeof(char) * dstsize + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < dstsize - 1 && src[i] && dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (dst);
}

static char	*strcat_join(char *str, char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}

char	*str_join(char *s1, char *s2)
{
	char	*str;
	size_t	t_len;

	t_len = 0;
	if (!s1 || !s2)
		return (NULL);
	if (s1 && s2)
	{
		t_len = str_len(s1) + str_len(s2) + 1;
		str = malloc(sizeof(char) * t_len);
		if (!str)
			return (NULL);
		strcat_join(str, s1, s2);
		return (str);
	}
	return (NULL);
}

char	*str_dup(char *s1)
{
	size_t	i;
	char	*new;

	new = (char *) malloc(str_len(s1) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
