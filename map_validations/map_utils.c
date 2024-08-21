/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:50:57 by fmalungo          #+#    #+#             */
/*   Updated: 2024/08/15 11:51:01 by fmalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int		window_size(char **map, char flag)
{
    int		i;

    i = 0;
    if (flag == 'w')
    {
        while (map[0][++i]) ;
        return (i * 50);
    }
    else if (flag == 'h')
    {
        while (map[++i]) ;
        return (i * 50);
    }

    return (0);
}
