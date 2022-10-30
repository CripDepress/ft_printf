/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <akeawdou@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:04:04 by akeawdou          #+#    #+#             */
/*   Updated: 2022/10/30 22:37:18 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_format
{
	va_list	args;
	int		wdth;
	int		prec;
	int		zero;
	int		pnt;
	int		dash;
	int		hash;
	int		plus;
	int		sp;
	int		len;
	char	type;
}	t_format;

int		ft_hexlen(unsigned long n);
int		ft_strlen(char *s);
int		ft_hexlen(unsigned long n);
int		ft_printf(const char *s, ...);
int		ft_format(const char *s, int i, t_format *fmt);
void	ft_print_format(t_format *fmt);
void	ft_set_format(char const *s, t_format *fmt);
void	ft_format_init(t_format *f);
void	ft_setstar(t_format *fmt);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_print_char(t_format *fmt);
void	ft_print_str(t_format *fmt);
void	ft_print_ptr(t_format *fmt);
void	ft_print_int(t_format *fmt);
void	ft_print_hex(t_format *fmt);
void	ft_print_unsign(t_format *fmt);
void	ft_print_prefix_u(unsigned int n, int len, t_format *fmt);

#endif
