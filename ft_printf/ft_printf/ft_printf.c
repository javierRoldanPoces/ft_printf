/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:31 by jroldan-          #+#    #+#             */
/*   Updated: 2023/01/18 09:01:04 by jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *fnt, ...)
{
	va_list	args;
	int		len;
	char	*p;

	len = 0;
	p = (char *)fnt;
	va_start(args, fnt);
	while (*p != '\0')
	{
		if (*p == '%' && *(p + 1) == 'c')
		{
			ft_putchar(va_arg(args, int), &len);
			p = p + 2;
		}
		if (*p == '%' && *(p + 1) == 's')
		{
			len = len + ft_putstr(va_arg(args, char *));
			p = p + 1;
		}
		if (*p == '%' && *(p + 1) == 'p')
		{
			ft_putstr("0x");
			ft_putnbr_base(va_arg(args, char *), "0123456789abcdef", &len);
			p = p + 2;
		}
		if (*p == '%' && *(p + 1) == 'd')
		{
			ft_putnbr_base(va_arg(args, long *), "0123456789", &len);
			p = p + 2;
		}/*
		if (*p == '%' && *(p + 1) == 'i')
		{
			ft_putnbr_base(va_arg(args, char *), "0123456789", &len);
			p = p + 1;
		}
		if (*p == '%' && *(p + 1) == 'u')
		{
			ft_putnbr_base(va_arg(args, char *), "0123456789", &len);
			p = p + 1;
		}
		if (*p == '%' && *(p + 1) == 'x')
		{
			ft_putnbr_base(va_arg(args, char *), "0123456789abcdef", &len);
			p = p + 2;
		}
		if (*p == '%' && *(p + 1) == 'X')
		{
			ft_putnbr_base(va_arg(args, char *), "0123456789ABCDEF", &len);
			p = p + 1;
		}	*/
		else
			ft_putchar(*p, &len);
		p++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	char	c;

	c = 'b';
	ft_printf("%c %s", 's', "Adios");
	printf("\nOriginal p : %p\n", &c);
	ft_printf("\nMi funcion p : %p\n", &c);
	printf("\nOriginal d: %d\n", -98);
	ft_printf("\nMi funcion d: %d\n", -98);
	
/*	printf("\nOriginal i: %i\n", 42);
	ft_printf("\nMi funcion i: %i\n", 42);
	printf("\nOriginal u: %u\n", 39);
	ft_printf("\nMi funcion u: %u\n", 39);
	printf("\nOriginal x: %x\n", 9900);
	ft_printf("\nMi funcion x: %x\n", 9900);
	printf("\nOriginal X: %X\n", 9900);
	ft_printf("\nMi funcion X: %X\n", 9900);
*/
}
