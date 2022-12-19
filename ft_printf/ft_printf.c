/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:51:34 by darakely          #+#    #+#             */
/*   Updated: 2022/10/28 00:13:41 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int print_char(char c)
{
	return (write(1, &c, 1));
}

int ft_strlen(char *str)
{
	int i = -1;
	while (str[++i]) 
		;
	return i;
}

int print_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int print_hex(unsigned int	i)
{
	int len = 0;
	char*	hex = "abcdef";
	if (i <= 9)
		len += print_char(i + '0');
	else if (i < 16)
		len += print_char(hex[i - 10]);
	else
	{
		len += print_hex(i / 16);
		len += print_hex(i % 16);
	}
	return len;
}

int print_nbr(int i)
{
	int len = 0;
	long int nbr = i;
	if (nbr < 0)
	{
		len += print_char('-');
		nbr = -nbr;
	}
	if (nbr <= 9)
		len += print_char(nbr + '0');
	else
	{
		len += print_nbr(nbr / 10);
		len += print_nbr(nbr % 10);
	}
	return len;
}

int	ft_printf(const char *str, ...)
{
	int len = 0;
	va_list	arg;
	va_start(arg, str);
	int i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
				len += print_str(va_arg(arg, char*));
			if (str[i + 1] == 'x')
				len += print_hex(va_arg(arg, unsigned int));
			if (str[i + 1] == 'd')
				len += print_nbr(va_arg(arg, int));
			i++;
		}
		else
			len += print_char(str[i]);
		i++;
	}
	va_end(arg);
	return len;
}
