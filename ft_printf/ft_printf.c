/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:31 by jroldan-          #+#    #+#             */
/*   Updated: 2022/12/20 21:09:01 by jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

static void	ft_putnbr_base(int nbr, char *base, int *len)
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-', len);
		}
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]], len);
	}
}

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
			ft_putnbr_base(16, "123456789abcdefg", &len);
			ft_putstr("0x");
		}
		else
			ft_putchar(*p, &len);
		p++;
	}
	printf("\n%i",len);
	printf("\n%p", &p);
	va_end(args);
	return (len);
}

int	main(void)
{
	ft_printf("%c %s",'s', "Adios");

}
