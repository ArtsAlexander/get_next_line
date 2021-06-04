/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:12:15 by aarts             #+#    #+#             */
/*   Updated: 2021/06/04 19:33:34 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	putinline(char *saved, char **line)
{
	char	*temp;
	int		len;
	
	len = 0;
	while (saved[len] != '\n' && saved[len] != '\0')
		len++;
	if (saved[len] == '\n')
	{
		temp = str_dup(&saved[len + 1]);
		free(saved);
		saved = temp;
	}
	else
	{
		*line = str_dup(saved);
		free(saved);
	}
	return (1);
}

static int	output(char **saved, char **line, int ret, int fd)
{
	if (ret == 0 && saved[fd] == NULL)
		return (0);
	else
		return (putinline(saved[fd], line));
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = str_dup(buf);
		else
		{
			tmp = str_join(saved[fd], buf);
			free (saved[fd]);
			saved[fd] = tmp;
		}
		if (str_chr(saved[fd], '\n'))
			break ;
	}
	return (output(saved, line, ret, fd));
}
