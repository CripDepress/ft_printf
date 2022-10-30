/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:19:10 by akeawdou          #+#    #+#             */
/*   Updated: 2022/10/30 15:06:54 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenint(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_printnbr(t_format *fmt, int n)
{
	if (n == -2147483648)
	{
		fmt->len += write(1, "2147483648", 10);
		return ;
	}
	if (n < 0)
		ft_printnbr(fmt, -1 * n);
	else if (n < 10)
		fmt->len += write(1, &"0123456789"[n], 1);
	else
	{
		ft_printnbr(fmt, n / 10);
		fmt->len += write(1, &"0123456789"[n % 10], 1);
	}
}

void	ft_print_prefix(int n, int len, t_format *fmt)
{
	int	i;

	i = 0;
	if (fmt->plus && n >= 0)
		fmt->len += write(1, "+", 1);
	else if (n < 0)
		fmt->len += write(1, "-", 1);
	else if (fmt->sp)
		fmt->len += write(1, " ", 1);
	while (!fmt->dash && fmt->zero && fmt->wdth-- > \
			len + fmt->prec + (fmt->plus || fmt->sp || n < 0))
		fmt->len += write(1, "0", 1);
	while (fmt->prec - i++ > 0)
		fmt->len += write(1, "0", 1);
}

void	ft_print_int(t_format *fmt)
{
	int	n;
	int	len;

	n = va_arg(fmt->args, int);
	len = ft_lenint(n);
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
	while (!fmt->dash && !fmt->zero && fmt->wdth-- > \
			len + fmt->prec + (fmt->plus || fmt->sp || n < 0))
		fmt->len += write(1, " ", 1);
	ft_print_prefix(n, len, fmt);
	ft_printnbr(fmt, n);
	while (fmt->dash && fmt->wdth-- > \
			len + fmt->prec + (fmt->plus || fmt->sp || n < 0))
		fmt->len += write(1, " ", 1);
}
