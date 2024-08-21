/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:20:26 by fmalungo          #+#    #+#             */
/*   Updated: 2024/05/24 09:23:21 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>
# include<unistd.h>
# include<stdio.h>
# include<stddef.h>
# include<stdlib.h>

void	ft_putchar_num(char c, int *num_char);
void	ft_putstr(char *str, int *num_char);
void	ft_putnbr(int nb, int *num_digit);
void	ft_printbase(unsigned long long nbr,
			char *simbol, int *num_digit, unsigned int base);
void	ft_printptr(void *ptr, int *num_char);
int		ft_printf(const char *s, ...);
#endif
