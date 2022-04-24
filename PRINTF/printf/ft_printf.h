/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:07:00 by broy              #+#    #+#             */
/*   Updated: 2022/04/18 12:51:44 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_type(const char c, va_list ptr);
int		ft_printhexa(unsigned int n, const char c);
int		ft_printchar(int n);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_print_uint(unsigned int n);
int		ft_print_adress(unsigned long long n);
char	*ft_uita(unsigned int n);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
