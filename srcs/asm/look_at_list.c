/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/02/25 17:54:07 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_look_at_list(t_all *all)
{
	t_line *temp;

	temp = all->inc_list;
	if (temp == NULL)
		ft_error("where inSTRUction?\n");
	else if (all->name == NULL)
		ft_error("where NaMe?\n");
	else if (all->comment == NULL)
		ft_error("where cOmMeNt?\n");
	while (temp != NULL)
	{
		if (temp->line != NULL)
			ft_check_inc(all, temp);
		temp = temp->next;
	}
}

void	ft_check_inc(t_all *all, t_line *temp)
{
	int i;

	i = 0;
	while (all->inc[i] != NULL)
	{
		if (ft_strncmp(all->inc[i], temp->line, ft_strlen(all->inc[i])) == 0)
		{
			all->op[i](temp);
			return ;
		}
		i++;
	}
	ft_error("operation not exist!!!!");
}
