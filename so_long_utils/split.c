/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:51:18 by fmalungo          #+#    #+#             */
/*   Updated: 2024/08/15 11:51:22 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	function_1(const char *str, char c)
{
	int	counter;
	int	warn;

	counter = 0;
	warn = 0;
	while (*str)
	{
		if (*str != c && warn == 0)
		{
			warn = 1;
			counter++;
		}
		else if (*str == c)
			warn = 0;
		str++;
	}
	return (counter);
}

static char	*function_2(const char *str, int start, int end)
{
	char	*rtn;
	int		i;

	rtn = (char *)malloc(sizeof(char) * ((end - start) + 1));
	i = 0;
	while (start < end)
		rtn[i++] = str[start++];
	rtn[i] = 0;
	return (rtn);
}

static int	function_3(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**split(char const *s, char c)
{
	char	**out;
	int		i;
	int		start;
	int		j;

	if (!s)
		return (NULL);
	out = (char **)malloc(sizeof(char *) * (function_1(s, c) + 1));
	if (!out)
		return (NULL);
	start = -1;
	i = -1;
	j = 0;
	while (++i <= function_3(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == function_3(s)))
		{
			out[j++] = function_2(s, start, i);
			start = -1;
		}
	}
	out[j] = 0;
	return (out);
}
