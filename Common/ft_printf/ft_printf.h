/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:29:09 by gyeokim           #+#    #+#             */
/*   Updated: 2022/05/24 02:35:55 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		specifier(va_list ap, const char *format);
int		read_line(const char *format, int *idx, int *n);
void	ft_putchar_n(int c, int *n);
void	ft_putper(int *n);
void	ft_putstr_n(char *s, int *n);
void	ft_putint(int i, int *n);
void	ft_putuint(unsigned int u, int *n);
void	ft_putptr(unsigned long long p, int *n);
void	ft_convert_hex(unsigned int d, int c, int *n);
void	ft_putchar(char c);
int		ft_toupper(int c);

#endif
