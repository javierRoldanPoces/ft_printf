/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:31 by jroldan-          #+#    #+#             */
/*   Updated: 2023/01/19 20:55:31 by jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *fnt, ...)
{
	va_list	args;
	int		len;
	char	*p;
	char	*pn;

	len = 0;
	p = (char *)fnt;
	va_start(args, fnt);
	while (*p != '\0')
	{	
		pn = p + 1;
		if (*p == '%' && *pn == 'c')
		{
			ft_putchar(va_arg(args, int), &len);
			p += 1;
		}
		else if (*p == '%' && *pn == 's')
		{
			ft_putstr(va_arg(args, char *), &len);
			p = p + 1;
		}
		else if (*p == '%' && *pn == '%')
		{
			ft_putchar('%', &len);
			p += 1;
		}
		else if (*p == '%' && *pn == 'd')
		{
			ft_putnbr_base(va_arg(args, int), "0123456789", &len, pn);
			p = p + 1;
		}
		else if (*p == '%' && *pn == 'i')
		{
			ft_putnbr_base(va_arg(args, int), "0123456789", &len, pn);
			p = p + 1;
		}

/*			if (*p == '%' && *pn == 'x')
		{
			ft_putnbr_base(va_arg(args, char *), "0123456789abcdef", &len, pn);
			p = p + 2;
		}
			if (*p == '%' && *pn == 'p')
		{
			ft_putstr("0x");
			ft_putnbr_base(va_arg(args, char *), "0123456789abcdef", &len, pn);
			p = p + 1;
		}

		if (*p == '%' && *pn == 'u')
		{
			ft_putnbr_base(va_arg(args, char *), "0123456789", &len, pn);
			p = p + 2;
		}
		
		if (*p == '%' && *pn == 'X')
		{
			ft_putnbr_base(va_arg(args, char *), "0123456789ABCDEF", &len, pn);
			p = p + 1;
		}*/
		else
			ft_putchar(*p, &len);
		p = p + 1;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
 {
 	//char	c;

 	//c = 'b';
	//ft_printf("%c", '0'); 
	//printf("%c", '0');
 	//ft_printf("%s", "Hola juan");
	//printf(" NULL %s NULL \n", NULL);
	//ft_printf(" NULL %s NULL ", NULL);
	//printf("\n");
	//printf(" %c", '0' - 256);
	//ft_printf(" %c", '0' - 256);
	//printf(" %c", '0' - 256);

 	
	//printf("\nOriginal p : %p\n", &c);
 	//ft_printf("\nMi funcion p : %p\n", &c);
 	//printf("\nOriginal d: %d\n", LONG_MIN);
	printf(" %d ", 214748364789);
 	ft_printf("\nd: %d\n", 214748364789);
 	printf("\nOriginal i: %i\n", -2147483647);
 	ft_printf("\nMi funcion i: %i\n", -2147483647);
}

	//printf("\nOriginal u: %u\n", -39);
 	//ft_printf("\nMi funcion u: %u\n", -39);
 	//printf("\nOriginal x: %x\n", -9900);
 	//ft_printf("\nMi funcion x: %x\n", -9900);
 	//ft_printf("\nX: %X", -9900);
 	//printf("\nOriginal X: %X\n", -9900);

 }
 */