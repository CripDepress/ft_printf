/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:10:06 by akeawdou          #+#    #+#             */
/*   Updated: 2022/10/30 15:22:16 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(t_format *fmt)
{
	int		len;
	char	*s;

	s = va_arg(fmt->args, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (fmt->pnt != 0 && fmt->prec < len)
		len = fmt->prec;
	fmt->wdth -= len;
	if (!fmt->dash && fmt->wdth > 0)
		while (fmt->wdth-- != 0)
			fmt->len += write(1, " ", 1);
	if (fmt->type == 's')
		fmt->len += write(1, s, len);
	while (fmt->dash && fmt->wdth-- > 0)
		fmt->len += write(1, " ", 1);
}

void	ft_print_char(t_format *fmt)
{
	char	c;

	c = (char)va_arg(fmt->args, int);
	fmt->wdth -= 1;
	while (!fmt->dash && fmt->wdth-- > 0)
		fmt->len += write(1, " ", 1);
	fmt->len += write(1, &c, 1);
	while (fmt->dash && fmt->wdth-- > 0)
		fmt->len += write(1, " ", 1);
}
