/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:08:40 by aarts             #+#    #+#             */
/*   Updated: 2021/06/09 21:15:42 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif 

# ifndef FD_MAX
#  define FD_MAX 256
# endif

int		get_next_line(int fd, char **line);
char	*str_chr(char *s, int c);
char	*str_join(char *s1, char *s2);
char	*str_dup(char *s1);
char	*sub_str(char *s, size_t len);

#endif
