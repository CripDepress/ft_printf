/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:18:59 by akeawdou          #+#    #+#             */
/*   Updated: 2022/10/30 15:06:29 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_init(t_format *f)
{
		f->wdth = 0;
		f->prec = 0;
		f->zero = 0;
		f->pnt = 0;
		f->dash = 0;
		f->sp = 0;
		f->hash = 0;
		f->plus = 0;
		f->type = 0;
}

void	ft_setstar(t_format *fmt)
{
	int	val;

	val = va_arg(fmt->args, int);
	if (fmt->pnt)
		fmt->prec = val;
	else
	{
		if (val < 0)
		{
			fmt->dash = 1;
			val *= -1;
		}
		fmt->wdth = val;
	}
}

void	ft_set_format(char const *s, t_format *fmt)
{
	if (*s == 'c' || *s == 's' || *s == 'p' || *s == 'd' || \
			*s == 'i' || *s == 'u' || *s == 'x' || *s == 'X')
		fmt->type = *s;
	else if (*s == '-')
		fmt->dash = 1;
	else if (*s == '#')
		fmt->hash = 1;
	else if (*s == ' ')
		fmt->sp = 1;
	else if (*s == '+')
		fmt->plus = 1;
	else if (*s == '0' && fmt->pnt == 0 && fmt->wdth == 0)
		fmt->zero = 1;
	else if (*s == '.')
		fmt->pnt = 1;
	else if (*s == '*')
		ft_setstar(fmt);
	else if (*s >= '0' && *s <= '9')
	{
		if (fmt->pnt)
			fmt->prec = (fmt->prec * 10) + (*s - '0');
		else
			fmt->wdth = (fmt->wdth * 10) + (*s - '0');
	}
}
