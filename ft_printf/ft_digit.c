/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:50:29 by jroldan-          #+#    #+#             */
/*   Updated: 2023/01/18 09:02:52 by jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_putnbr_base(void *nbr, char *base, int *len)
{
	unsigned long	size_base;
	long			nbr_final[100];
	int				i;
	long			cast;

	cast = (long)nbr;
	i = 0;
	size_base = 0;
	if (cast < 0)
	{
		printf("\nEntra en el bucle control de signo");
		ft_putchar('-', len);
		cast = cast * -1;
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