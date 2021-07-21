/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:12:15 by aarts             #+#    #+#             */
/*   Updated: 2021/07/21 20:05:36 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

static char	*putinline_final(char **saved_fd, char *line)
{
	line = str_dup(*saved_fd);
	if (!line)
		return (ft_free(line));
	free(*saved_fd);
	*saved_fd = NULL;
	return (line);
}

static char	*putinline(char **saved_fd)
{
	char	*temp;
	char	*line;
	size_t	i;

	i = 0;
	while ((*saved_fd)[i] != '\n' && (*saved_fd)[i] != '\0')
		i++;
	line = NULL;
	if ((*saved_fd)[i] == '\n')
	{
		line = sub_str((*saved_fd), i + 1);
		if (!line)
			return (ft_free(line));
		temp = str_dup(&(*saved_fd)[i + 1]);
		if (!temp)
			return (ft_free(temp));
		free(*saved_fd);
		*saved_fd = temp;
	}
	else
		return (putinline_final(saved_fd, line));
	return (line);
}

static int	gnl_loop(char **saved, char *buf, int fd, int ret)
{
	char	*tmp;
	
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	if (saved[fd] == NULL)
	{
		saved[fd] = str_dup(buf);
		if (!saved[fd] || ret == 0)
		{
			free(saved[fd]);
			return (-1);
		}
	}
	else
	{
		tmp = str_join(saved[fd], buf);
		if (!tmp)
		{
			free(tmp);
			return (-1);
		}
		free(saved[fd]);
		saved[fd] = tmp;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*saved[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = gnl_loop(saved, buf, fd, ret);
		if (ret == -1)
			return (NULL);
		if (str_chr(saved[fd], '\n'))
			break ;
	}
	return (putinline(&saved[fd]));
}
