/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:36:55 by akeawdou          #+#    #+#             */
/*   Updated: 2022/10/31 00:26:48 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	ft_puthex(unsigned int n, t_format *fmt)
{
	if (fmt->type == 'x' || fmt->type == 'p' || fmt->type == 'u')
		fmt->len += write(1, &"0123456789abcdef"[n], 1);
	else if (fmt->type == 'X')
		fmt->len += write(1, &"0123456789ABCDEF"[n], 1);
}

void	recur_base(unsigned int n, t_format *fmt, size_t base)
{
	if (n >= base)
		recur_base(n / base, fmt, base);
	n %= base;
	ft_puthex(n, fmt);
}

void	ft_print_hex_pf(unsigned int n, int len, t_format *fmt)
{
	if (fmt->hash && n != 0)
	{
		if (fmt->type == 'x')
			fmt->len += write(1, "0x", 2);
		else if (fmt->type == 'X')
			fmt->len += write(1, "0X", 2);
	}
	while (!fmt->dash && !fmt->zero && fmt->wdth-- > \
			len + fmt->prec + (fmt->plus || fmt->sp))
		fmt->len += write(1, " ", 1);
}

void	ft_print_hex(t_format *fmt)
{
	unsigned int	n;
	int				len;

	n = va_arg(fmt->args, unsigned int);
	len = ft_hexlen(n);
	if (n == 0 && fmt->pnt && fmt->prec == 0)
	{
		while (fmt->wdth-- >= len)
			fmt->len += write(1, " ", 1);
		return ;
	}
	if (fmt->wdth > fmt->prec && fmt->prec != 0)
		fmt->zero = 0;
	if (fmt->prec > len)
		fmt->prec -= len;
	else
		fmt->prec = 0;
	ft_print_hex_pf(n, len, fmt);
	ft_print_prefix_u(n, len, fmt);
	recur_base(n, fmt, 16);
	while (fmt->dash && fmt->wdth-- > \
			len + fmt->prec + (fmt->plus || fmt->sp))
		fmt->len += write(1, " ", 1);
}
