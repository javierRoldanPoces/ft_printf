/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:31:18 by jroldan-          #+#    #+#             */
/*   Updated: 2022/12/20 20:33:25 by jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

static size_t	ft_strlen(const char *s)
{	
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}