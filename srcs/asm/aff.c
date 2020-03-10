/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/07 15:47:36 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	aff(t_line *temp)
{
	char	*new;

	if (temp->line[3] == ' ' || temp->line[3] == '\t')
		new = ft_afterspace(temp->line + 3);
	else
		ft_error("error with affff : aff command\n");
	temp->arg = ft_strsplit_wide(new, SEPARATOR_CHAR);
	if (ft_size_mass(temp->arg) != 1 || ft_h_m(new, SEPARATOR_CHAR) != 0)
		ft_error("error with number of arg : aff command\n");
	ft_trim_mass_arg(temp->arg);
	ft_check_reg(temp->arg[0]);
	temp->op = 16;
	temp->size = 1 + 1 + 1;
	temp->cod = 64;
	temp->flag = 1;
}
