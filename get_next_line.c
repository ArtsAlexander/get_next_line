/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:12:15 by aarts             #+#    #+#             */
/*   Updated: 2021/06/08 22:54:58 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static int	putinline(char **saved_fd, char **line)
{
	char	*temp;
	size_t	i;

	i = 0;
	while ((*saved_fd)[i] != '\n' && (*saved_fd)[i] != '\0')
		i++;
	if ((*saved_fd)[i] == '\n')
	{
		*line = strl_cpy((*saved_fd), i);
		temp = str_dup(&(*saved_fd)[i + 1]);
		free(*saved_fd);
		(*saved_fd) = temp;
	}
	else
	{
		*line = str_dup(*saved_fd);
		if (*saved_fd != NULL)
		{
			free(*saved_fd);
			*saved_fd = NULL;
		}
	}
	return (1);
}

static int	output(char **saved_fd, char **line, int ret)
{
	if (ret == 0 && *saved_fd == NULL)
		return (0);
	else
		return (putinline(saved_fd, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || !line || FD_MAX < fd || BUFFER_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (saved[fd] == NULL)
			saved[fd] = str_dup(buf);
		else
		{
			buf[ret] = '\0';
			tmp = str_join(saved[fd], buf);
			free(saved[fd]);
			saved[fd] = tmp;
		}
		if (str_chr(saved[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	return (output(&saved[fd], line, ret));
}
