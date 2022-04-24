/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:16:57 by broy              #+#    #+#             */
/*   Updated: 2022/04/22 15:01:45 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strchr(char *save, int c);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_get_line(char *save);
char		*ft_save(char *save);
char		*ft_read_file(int fd, char *save);
char		*ft_strdup(const char *s);

#endif
