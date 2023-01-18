/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copia_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:50:29 by jroldan-          #+#    #+#             */
/*   Updated: 2023/01/18 08:41:48 by jroldan-         ###   ########.fr       */
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

int	*ft_putnbr_base(void *nbr, char *base, int *len)
{
	unsigned long		size_base;
	unsigned long		nbr_final[100];
	long				i;
	unsigned long long	cast;

	cast = (long)nbr;
	i = 0;
	size_base = 0;
	if (check_base(base))
	{
	/*	if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-', len);
		}
		while (base[size_base])
			size_base++;
		while (cast)
		{
			nbr_final[i] = cast % size_base;
			cast = cast / size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]], len);
	}
	return (len);
}
/*
void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = i * -1;
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putchar((i % 10) + 48, fd);
	}
	if (i <= 9)
	{
		ft_putchar(i + '0', fd);
	}
}
*/