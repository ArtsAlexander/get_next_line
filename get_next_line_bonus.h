/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:08:40 by aarts             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/06/10 13:59:39 by aarts            ###   ########.fr       */
=======
/*   Updated: 2021/06/10 13:09:03 by aarts            ###   ########.fr       */
>>>>>>> 5d7de74d03d8221cf129ddb72901b5f0de319049
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

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
