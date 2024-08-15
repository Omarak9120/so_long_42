/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:12:40 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/14 20:21:48 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	gft_strlen(const char *str);
char	*gft_strchr(const char *s, int c);
char	*gft_strjoin(char const *s1, char const *s2);
char	*gft_strdup(const char *s1);
size_t	find_newline(const char *s);
char	*copy_line(const char *buffer, size_t length);
char	*update_buffer(char *buffer, size_t start);
char	*read_and_buffer(int fd, char *buffer);

#endif
