/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:31 by jroldan-          #+#    #+#             */
/*   Updated: 2023/01/25 11:21:45 by jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static condition (char *p,va_list args, char *fnt, int *len)
{

}*/

int	ft_printf(char const *fnt, ...)
{
	va_list	args;
	int		len;
	char	*p;

	len = 0;
	p = (char *)fnt;
	va_start(args, fnt);
	if ((write (1, "", 0) == -1))
		return (-1);
	while (*p != '\0')
	{	
		if (*p == '%' && *(p + 1) == 'c')
		{
			ft_putchar(va_arg(args, int), &len);
			p += 1;
		}
		else if (*p == '%' && *(p + 1) == 's')
		{
			ft_putstr(va_arg(args, char *), &len);
			p += 1;
		}
		else if (*p == '%' && *(p + 1) == '%')
		{
			ft_putchar('%', &len);
			p += 1;
		}
		else if (*p == '%' && *(p + 1) == 'd' | *(p + 1) == 'i')
		{
			ft_putnbr_d_i(va_arg(args, int), &len);
			p += 1;
		}
		else if (*p == '%' && *(p + 1) == 'p')
		{
			ft_putstr("0x", &len);
			ft_putnbr_p(va_arg(args, unsigned long), "0123456789abcdef", &len);
			p += 1;
		}
		else if (*p == '%' && (*(p + 1) == 'x' | *(p + 1) == 'X'))
		{
			ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef", &len, p);
			p += 1;
		}
		else if (*p == '%' && *(p + 1) == 'u')
		{
			ft_putnbr_unsigned_d(va_arg(args, unsigned int), &len);
			p += 1;
		}
		else
			ft_putchar(*p, &len);
		p += 1;
	}
	va_end(args);
	return (len);
}
