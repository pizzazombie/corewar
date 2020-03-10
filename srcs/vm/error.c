/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:28:27 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/07 14:02:02 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_error(char *line, int i)
{
	ft_putstr(ANSI_COLOR_RED);
	ft_putstr(line);
	ft_putstr(ANSI_COLOR_RESET);
	ft_putstr("\n");
	exit(i == -1 ? i : -1);
}
