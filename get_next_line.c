/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:12:15 by aarts             #+#    #+#             */
/*   Updated: 2021/07/01 20:38:09 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	freeandreturn(char *str)
{
	free(str);
	str = NULL;
	return (-1);
}

static int	putloop(char *line, char *saved_fd)
{
	*line = str_dup(*saved_fd);
	if (!(*line))
		return(freeandreturn(*line));
	free(*saved_fd);
	*saved_fd = NULL;
	return (0);
}

static int	putinline(char **saved_fd, char **line)
{
	char	*temp;
	size_t	i;

	i = 0;
	while ((*saved_fd)[i] != '\n' && (*saved_fd)[i] != '\0')
		i++;
	if ((*saved_fd)[i] == '\n')
	{
		*line = sub_str((*saved_fd), i);
		if (!(*line))
			return(freeandreturn(*line));
		temp = str_dup(&(*saved_fd)[i + 1]);
		if (!temp)
			return(freeandreturn(temp));
		free(*saved_fd);
		*saved_fd = temp;
	}
	else
		return(putloop(line, saved_fd));
	return (1);
}


int	get_next_line(int fd, char **line)
{
	static char	*saved[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (saved[fd] == NULL)
		{
			saved[fd] = str_dup(buf);
			if (!saved[fd])
				return(freeandreturn(saved[fd]));
		}
		else
		{
			tmp = str_join(saved[fd], buf);
			if (!tmp)
				return(freeandreturn(tmp));
			free(saved[fd]);
			saved[fd] = tmp;
		}
		if (str_chr(saved[fd], '\n'))
			break ;
	}
	return (putinline(&saved[fd], line));
}
