/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:42 by jroldan-          #+#    #+#             */
/*   Updated: 2023/01/18 07:38:16 by jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

void		ft_putchar(char c, int *len);
int			ft_printf(char const *fnt, ...);
int			ft_putstr(char *s);
//static int	check_base(char *base);
int			*ft_putnbr_base(void *nbr, char *base, int *len);

#endif
