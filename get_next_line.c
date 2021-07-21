/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:12:15 by aarts             #+#    #+#             */
/*   Updated: 2021/07/21 18:55:23 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

static char	*putinline2(char **saved_fd, char *line)
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
		return (putinline2(saved_fd, line));
	return(line);
}

char	*get_next_line(int fd)
{
	static char	*saved[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;
	
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (saved[fd] == NULL)
		{
			saved[fd] = str_dup(buf);
			if (!saved[fd] || ret == 0)
				return (ft_free(saved[fd]));
		}
		else
		{
			tmp = str_join(saved[fd], buf);
			if (!tmp)
				return (ft_free(tmp));
			free(saved[fd]);
			saved[fd] = tmp;
		}
		if (str_chr(saved[fd], '\n'))
			break ;
	}
	return (putinline(&saved[fd]));
}
