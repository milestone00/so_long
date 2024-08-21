/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:43:56 by fmalungo          #+#    #+#             */
/*   Updated: 2024/05/24 13:39:00 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_check_identif(va_list args, const char *s, int *num_char)
{
	if (*s == 'c')
		ft_putchar_num(va_arg(args, int), num_char);
	else if (*s == 's')
		ft_putstr(va_arg(args, char *), num_char);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, int), num_char);
	else if (*s == 'x')
	{
		ft_printbase(va_arg(args, unsigned int),
			"0123456789abcdef", num_char, 16);
	}
	else if (*s == 'X')
	{
		ft_printbase(va_arg(args, unsigned int),
			"0123456789ABCDEF", num_char, 16);
	}
	else if (*s == 'u')
	{
		ft_printbase(va_arg(args, unsigned int),
			"0123456789", num_char, 10);
	}
	else if (*s == 'p')
		ft_printptr(va_arg(args, void *), num_char);
	else if (*s == '%')
		ft_putchar_num(*s, num_char);
}

int	ft_printf(const char *s, ...)
{
	int			num_char;
	va_list		args;

	va_start(args, s);
	num_char = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_check_identif(args, s, &num_char);
		}
		else
			ft_putchar_num(*s, &num_char);
		s++;
	}
	return (num_char);
}
/*
int	main(void)
{
	void *ptr = (void *)NULL;
	printf("%d\n",101);
	ft_printf("%p", ptr,12,13,14,15);
	return (0);
}*/
