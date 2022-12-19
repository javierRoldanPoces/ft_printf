/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroldan- <jroldan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:31 by jroldan-          #+#    #+#             */
/*   Updated: 2022/12/19 20:07:43 by jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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

static char	*ft_strrchr(const char *s, int c)
{
	int		lastc;
	int		i;
	char	*scpy;

	i = 0;
	lastc = -1;
	scpy = (char *)s;
	if ((char)c == '\0')
		return (&(scpy[ft_strlen(scpy)]));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			lastc = i;
		i++;
	}
	if (lastc == -1)
		return (NULL);
	return (&scpy[lastc]);
}


int	ft_printf(char const *argslist, ...)
{
	va_list	args;
	char	*ptr;

	va_start(args, argslist);
	printf("argslist: %s\n", argslist);
	
	ptr = va_arg(args, char *);	
	while (ptr)
	{
		if (*ptr == '%' && ptr[1] == 's')
		{
			putstr(va_arg(args, char *);)
			ptr++;
		}
		else if (*ptr == '%' && ptr[1] == 'c')
		{
			putchar(va_arg(args, char *);
			ptr++
		}
		else{
			putchar(*ptr);
		}
		ptr++;
		

	}
	printf("ptr: %s\n", ptr);
	ptr = va_arg(args, char *);
	printf("ptr1: %s\n", ptr);
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("hol%sdsdsds","hola dkdfdf");
}
