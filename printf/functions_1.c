/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:01:02 by fmalungo          #+#    #+#             */
/*   Updated: 2024/05/24 13:43:31 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_num(char c, int *num_char)
{
	write(1, &c, 1);
	(*num_char)++;
}

void	ft_putstr(char *s, int *num_char)
{
	if (s == NULL)
		ft_putstr("(null)", num_char);
	else
	{
		while (*s)
		{
			ft_putchar_num(*s, num_char);
			s++;
		}
	}
}

void	ft_putnbr(int nb, int *num_digit)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648", num_digit);
	else if (nb < 0)
	{
		ft_putchar_num('-', num_digit);
		nb = -nb;
		ft_putnbr(nb, num_digit);
	}
	else if (nb > 9)
	{
		ft_putnbr((nb / 10), num_digit);
		ft_putchar_num((nb % 10) + 48, num_digit);
	}
	else
		ft_putchar_num(nb + 48, num_digit);
}

void	ft_printbase(unsigned long long nbr, char *simbol,
			int *num_digit, unsigned int base)
{
	if (nbr >= base)
		ft_printbase(nbr / base, simbol, num_digit, base);
	ft_putchar_num(simbol[nbr % base], num_digit);
}

void	ft_printptr(void *ptr, int *num_char)
{
	unsigned long	p;

	p = (unsigned long)ptr;
	if (ptr != NULL)
	{
		ft_putstr("0x", num_char);
		ft_printbase(p, "0123456789abcdef", num_char, 16);
	}	
	else
	{
		ft_putstr("(nil)", num_char);
	}
}
