/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:16:49 by akeawdou          #+#    #+#             */
/*   Updated: 2022/10/30 15:07:09 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(t_format *fmt, unsigned long n)
{
	if (n < 16)
		fmt->len += write(1, &"0123456789abcdef"[n], 1);
	else
	{
		ft_putptr(fmt, n / 16);
		fmt->len += write(1, &"0123456789abcdef"[n % 16], 1);
	}
}

void	ft_print_ptr(t_format *fmt)
{
	unsigned long	n;
	int				len;

	n = va_arg(fmt->args, unsigned long);
	len = ft_hexlen(n);
	fmt->wdth -= len + 2;
	while (!fmt->dash && fmt->wdth-- > 0)
		fmt->len += write(1, " ", 1);
	fmt->len += write(1, "0x", 2);
	ft_putptr(fmt, n);
	while (fmt->dash && fmt->wdth-- > 0)
		fmt->len += write(1, " ", 1);
}
