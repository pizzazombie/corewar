/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/07 15:48:54 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	lldi(t_line *temp)
{
	char	*new;

	if (temp->line[4] == ' ' || temp->line[4] == '\t')
		new = ft_afterspace(temp->line + 4);
	else
		ft_error("error with ldi : lldi command need space\n");
	temp->arg = ft_strsplit_wide(new, SEPARATOR_CHAR);
	if (ft_size_mass(temp->arg) != 3 || ft_h_m(new, SEPARATOR_CHAR) != 2)
		ft_error("error with number of arg : lldi command\n");
	ft_trim_mass_arg(temp->arg);
	temp->cod += ft_check_trio(temp->arg[0], 1, temp, IND_SIZE);
	ft_check_double(temp->arg[1], 2, temp);
	ft_check_reg(temp->arg[2]);
	temp->cod += 4;
	temp->size += 1 + 1 + 1;
	temp->op = 14;
	temp->dir = IND_SIZE;
	temp->flag = 1;
}
