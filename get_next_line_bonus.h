/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:08:40 by aarts             #+#    #+#             */
/*   Updated: 2021/07/22 17:59:18 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif 

char	*get_next_line(int fd);
char	*str_chr(char *s, int c);
char	*str_join(char *s1, char *s2);
char	*str_dup(char *s1);
char	*sub_str(char *s, size_t len);

#endif
