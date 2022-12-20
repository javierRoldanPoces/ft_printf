/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:42 by jroldan-          #+#    #+#             */
/*   Updated: 2022/12/20 20:41:13 by jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

static void		ft_putchar(char c, int *len);
int				ft_printf(char const *fnt, ...);
static int		ft_putstr(char *s);
static int		check_base(char *base);
static void		ft_putnbr_base(int nbr, char *base);

#endif
