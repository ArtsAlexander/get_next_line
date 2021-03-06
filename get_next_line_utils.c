/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:14:01 by aarts             #+#    #+#             */
/*   Updated: 2021/07/21 17:24:28 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_chr(char *s, int c)
{
	char	*pointer;

	pointer = (char *)s;
	while (pointer && *pointer)
	{
		if (*pointer == (char) c)
			return (pointer);
		pointer++;
	}
	if (pointer && *pointer == 0 && (char) c == 0)
		return (pointer);
	return (NULL);
}

static size_t	str_len(char *s)
{
	size_t	count;

	count = 0;
	while (s && s[count])
		count++;
	return (count);
}

char	*sub_str(char *s, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*str;

	if (!s)
		return (NULL);
	s_len = str_len(s);
	if (s_len < len)
		len = s_len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[i];
	str[i] = 0;
	return (str);
}

char	*str_dup(char *s1)
{
	size_t	i;
	char	*new;

	if (!s1)
		return (NULL);
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

char	*str_join(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*cat;

	if (s1 == NULL)
		return (str_dup(s2));
	if (s2 == NULL)
		return (str_dup(s1));
	len = str_len(s1) + str_len(s2);
	i = 0;
	cat = (char *)malloc(sizeof(char) * (len + 1));
	if (cat == NULL)
		return (NULL);
	while (*s1 != '\0')
		cat[i++] = *s1++;
	while (*s2 != '\0')
		cat[i++] = *s2++;
	cat[i] = '\0';
	return (cat);
}
