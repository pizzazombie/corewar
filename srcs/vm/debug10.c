/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:14 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/10 14:00:07 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	debug10(t_cursor *temp, t_debug *deb)
{
	int				num;

	num = *(temp->registrs + deb->reg - 1);
	deb->pc = looped(temp->pc, 3);
	ft_printf("%02x%02x%02x%02x", (num >> 24) & 0xff, (num >> 16) & 0xff,
			(num >> 8) & 0xff, (num >> 0) & 0xff);
	ft_printf(" -> \"%02x%02x%02x%02x\"", *(deb->field + looped(num, 0)),
			*(deb->field + looped(num, 1)), *(deb->field + looped(num, 2)),
					*(deb->field + looped(num, 3)));
}

int		debug10_num1(t_cursor *temp, t_debug *deb, int num)
{
	int num1;

	if (deb->arg & 0x20 && deb->arg & 0x10)
	{
		num1 = get_indirect(deb->field, deb->pc, temp->pc);
		ft_printf("r%u (%d) -> (PC (%u) + (at %d steps + ",
				deb->reg, num, temp->pc, num1);
		deb->pc = looped(deb->pc, 2);
	}
	else if (deb->arg & 0x10)
	{
		num1 = *(temp->registrs + *(deb->field + deb->pc) - 1);
		ft_printf("r%u (%d) -> (PC (%u) + (r%u (%d) + ", deb->reg,
				num, temp->pc, *(deb->field + deb->pc), num1);
		deb->pc = looped(deb->pc, 1);
	}
	else
	{
		num1 = get_direct(deb->field, deb->pc, 0);
		ft_printf("r%u (%d) -> (PC (%u) + (%d + ", deb->reg, num, \
															temp->pc, num1);
		deb->pc = looped(deb->pc, 2);
	}
	return (num1);
}

int		debug10_num2(t_cursor *temp, t_debug *deb, int num, int num1)
{
	int num2;

	if (deb->arg & 0x4)
	{
		num2 = *(temp->registrs + *(deb->field + deb->pc) - 1);
		num = looped(temp->pc, (num1 + num2) % IDX_MOD);
		ft_printf("r%u (%d)) %% IDX_MOD = %u -> ",
				*(deb->field + deb->pc), num2, num);
		deb->pc = looped(deb->pc, 1);
	}
	else
	{
		num2 = get_direct(deb->field, deb->pc, 0);
		num = looped(temp->pc, (num1 + num2) % IDX_MOD);
		ft_printf("%d) %% IDX_MOD = %u == ", num2, num);
		deb->pc = looped(deb->pc, 2);
	}
	return (num2);
}
