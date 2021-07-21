/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:12:15 by aarts             #+#    #+#             */
/*   Updated: 2021/07/21 17:24:27 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*putinline(char **saved_fd, char **line)
{
	char	*temp;
	size_t	i;

	i = 0;
	while ((*saved_fd)[i] != '\n' && (*saved_fd)[i] != '\0')
		i++;
	if ((*saved_fd)[i] == '\n')
	{
		*line = sub_str((*saved_fd), i + 1);
		temp = str_dup(&(*saved_fd)[i + 1]);
		if (!temp || !(*line))
			return (ft_free());
		free(*saved_fd);
		*saved_fd = temp;
	}
	else
	{
		*line = str_dup(*saved_fd);
		if (*line)
			return (ft_free(*line))
		free(*saved_fd);
		*saved_fd = NULL;
	}
	return(*line);
}

char	*get_next_line(int fd)
{
	static char	*saved[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	char		*line;
	int			ret;
	
	printf("--%s--", saved[fd]);
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (saved[fd] == NULL)
		{
			if (!buf[0])
				return (NULL);
			saved[fd] = str_dup(buf);
			if (!saved[fd])
				return (NULL);
		}
		else
		{
			tmp = str_join(saved[fd], buf);
			if (!tmp)
				return (NULL);
			free(saved[fd]);
			saved[fd] = tmp;
		}
		if (str_chr(saved[fd], '\n'))
			break ;
	}
	return (putinline(&saved[fd], &line));
}
