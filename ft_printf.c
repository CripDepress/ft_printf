/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeawdou <akeawdou@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:12:02 by akeawdou          #+#    #+#             */
/*   Updated: 2022/10/30 15:23:01 by akeawdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_format(t_format *fmt)
{
	if (fmt->type == 's')
		ft_print_str(fmt);
	else if (fmt->type == 'c')
		ft_print_char(fmt);
	else if (fmt->type == 'p')
		ft_print_ptr(fmt);
	else if (fmt->type == 'd' || fmt->type == 'i')
		ft_print_int(fmt);
	else if (fmt->type == 'u')
		ft_print_unsign(fmt);
	else if (fmt->type == 'x' || fmt->type == 'X')
		ft_print_hex(fmt);
}

int	ft_format(const char *s, int i, t_format *fmt)
{
	if (!s[i])
		return (i);
	if (s[i] == '%')
	{
		write(1, "%", 1);
		fmt->len++;
		return (i);
	}
	else
	{
		while (s[i])
		{
			ft_set_format(s + i, fmt);
			if (fmt->type)
			{
				ft_print_format(fmt);
				ft_format_init(fmt);
				return (i);
			}
			i++;
		}
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			ret;
	t_format	*fmt;

	if (!s)
		return (0);
	fmt = (t_format *)malloc(sizeof (t_format));
	if (!fmt)
		return (-1);
	ft_format_init(fmt);
	fmt->len = 0;
	va_start(fmt->args, s);
	ret = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
			i = ft_format(s, i + 1, fmt);
		else
			ret += write(1, s + i, 1);
	}
	va_end(fmt->args);
	ret += fmt->len;
	free(fmt);
	return (ret);
}
