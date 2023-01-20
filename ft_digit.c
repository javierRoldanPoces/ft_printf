/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:50:29 by jroldan-          #+#    #+#             */
/*   Updated: 2023/01/20 13:49:37 by jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static void	recursiva_long(long nbr, long size, char *base, int *len)
{
	if (nbr >= size)
	{
		recursiva_long((nbr / size), size, base, len);
		ft_putchar(base[nbr % size], length);
	}
	else
		ft_putchar(base[nbr % size], length);
}
*/

void	ft_putnbr_base(int nbr, char *base, int *len, char *p)
{
	int			size_base;
	int		nbr_final[100];
	int				i;
	int		cast;

	i = 0;
	size_base = 0;

	/*
	if (*p == 'u' || *p == 'x' || *p == 'X')
		cast = (unsigned int)nbr;
	if (*p == 'p')
		cast = (unsigned long)nbr;
		*/
	if (*p == 'i' )
	{
		cast = nbr;
		if (cast == -2147483648)
		{
			write(1, "-2", 2);
			cast = 147483648;
			(*len)+=2; 

		}
		if (nbr == 0)
		{
			write(1, "0", 2);
			len++;
			printf("entra");
		}
		if (cast < 0)
		{
			ft_putchar('-', len);
			cast = cast * -1;
		}
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

// unsigned int son todos lo x y la U ---echo
// d e i son int c                    --echo
// p unsigned long					 --echo
// controlar los null				-- echo en string
