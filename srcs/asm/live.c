/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/07 15:48:36 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	live(t_line *temp)
{
	char	*new;

	if (temp->line[4] == ' ' || temp->line[4] == '\t')
		new = ft_afterspace(temp->line + 4);
	else
		new = temp->line + 4;
	if (new[0] == DIRECT_CHAR)
	{
		temp->arg = ft_strsplit_wide(new, SEPARATOR_CHAR);
		if (ft_size_mass(temp->arg) != 1 ||
				ft_h_m(new, SEPARATOR_CHAR) != 0)
			ft_error("error with number of arg : live command\n");
		ft_trim_mass_arg(temp->arg);
		if (temp->arg[0][1] == LABEL_CHAR)
			ft_check_ls_label(temp->arg[0] + 2);
		else
			ft_check_ld_number(temp->arg[0] + 1);
	}
	else
		ft_error("some not work with LIVE command\n");
	temp->op = 1;
	temp->size = 1 + DIR_SIZE;
	temp->flag = 1;
}
