/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:32:24 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/09 17:52:42 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  10
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strchr(const char *src, int c);
char	*ft_strjoin_2(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);

#endif