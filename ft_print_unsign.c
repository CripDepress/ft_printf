/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:38:29 by akeawdou          #+#    #+#             */
/*   Updated: 2022/10/30 22:37:45 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenint_u(unsigned int n)
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

void	ft_printnbr_u(t_format *fmt, unsigned int n)
{
	if (n < 0)
		ft_printnbr_u(fmt, -1 * n);
	else if (n < 10)
		fmt->len += write(1, &"0123456789"[n], 1);
	else
	{
		ft_printnbr_u(fmt, n / 10);
		fmt->len += write(1, &"0123456789"[n % 10], 1);
	}
}

void	ft_print_prefix_u(unsigned int n, int len, t_format *fmt)
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

void	ft_print_unsign(t_format *fmt)
{
	unsigned int	n;
	int				len;

	n = va_arg(fmt->args, unsigned int);
	len = ft_lenint_u(n);
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
			len + fmt->prec + (fmt->plus || fmt->sp))
		fmt->len += write(1, " ", 1);
	ft_print_prefix_u(n, len, fmt);
	ft_printnbr_u(fmt, n);
	while (fmt->dash && fmt->wdth-- > \
			len + fmt->prec + (fmt->plus || fmt->sp))
		fmt->len += write(1, " ", 1);
}
