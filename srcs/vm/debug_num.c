/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:14 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/10 14:03:00 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		debug_80_40(t_cursor *temp, char *s, t_debug *deb)
{
	int				num1;
	unsigned char	reg;

	if (deb->arg & 0x80 && deb->arg & 0x40)
	{
		ft_printf("at %d steps ", get_direct(deb->field, \
												looped(temp->pc, 2), 0));
		num1 = get_indirect(deb->field, looped(temp->pc, 2), temp->pc);
		ft_printf("(%x) %s ", num1, s);
		deb->pc = looped(temp->pc, 4);
	}
	else if (deb->arg & 0x80)
	{
		ft_printf("%x %s ", (num1 = get_direct(deb->field,
				looped(temp->pc, 2), 1)), s);
		deb->pc = looped(temp->pc, 6);
	}
	else
	{
		reg = *(deb->field + looped(temp->pc, 2));
		num1 = *(temp->registrs + reg - 1);
		ft_printf("r%u (%x) %s ", reg, num1, s);
		deb->pc = looped(temp->pc, 3);
	}
	return (num1);
}

int		debug_20_10(t_cursor *temp, t_debug *deb)
{
	int				num2;

	if (deb->arg & 0x20 && deb->arg & 0x10)
	{
		num2 = get_direct(deb->field, deb->pc, 0);
		ft_printf("at %d steps ", num2);
		num2 = get_indirect(deb->field, deb->pc, temp->pc);
		ft_printf("(%x)", num2);
		deb->pc = looped(deb->pc, 2);
	}
	else if (deb->arg & 0x20)
	{
		num2 = get_direct(deb->field, deb->pc, 1);
		ft_printf("%x", num2);
		deb->pc = looped(deb->pc, 4);
	}
	else
	{
		num2 = *(temp->registrs + *(deb->field + deb->pc) - 1);
		ft_printf("r%u (%x)", *(deb->field + deb->pc), num2);
		deb->pc = looped(deb->pc, 1);
	}
	return (num2);
}

int		debug_80_40_pc(t_cursor *temp, t_debug *deb)
{
	int				num1;

	deb->pc = looped(temp->pc, 2);
	if (deb->arg & 0x80 && deb->arg & 0x40)
	{
		num1 = get_indirect(deb->field, deb->pc, temp->pc);
		ft_printf("(PC (%u) + (at %02x%02x steps (%d) +", temp->pc,
				*(deb->field + deb->pc),
				*(deb->field + looped(deb->pc, 1)), num1);
		deb->pc = looped(deb->pc, 2);
	}
	else if (deb->arg & 0x40)
	{
		num1 = *(temp->registrs + *(deb->field + deb->pc) - 1);
		ft_printf("(PC (%u) + (r%u (%d) +", temp->pc,
				*(deb->field + deb->pc), num1);
		deb->pc = looped(deb->pc, 1);
	}
	else
	{
		num1 = get_direct(deb->field, deb->pc, 0);
		ft_printf("(PC (%u) + (%d +", temp->pc, num1);
		deb->pc = looped(deb->pc, 2);
	}
	return (num1);
}

void	debug_9_13(t_cursor *temp, t_debug *deb)
{
	int				num1;
	int				num2;
	unsigned char	reg;

	num1 = debug_80_40_pc(temp, deb);
	num2 = debug_idx_mod(temp, deb);
	reg = *(deb->field + deb->pc);
	num1 = looped(temp->pc, num1 + num2);
	num2 = get_direct(deb->field, num1, 1);
	if (deb->num == 9)
		ft_printf("%d ==== %02x%02x%02x%02x -> r%u", num1, (num2 >> 24) & 0xff,
				(num2 >> 16) & 0xff, (num2 >> 8) & 0xff,
						(num2 >> 0) & 0xff, reg);
	else
		ft_printf("%d ==== %02x%02x%02x%02x -> r%u + carry -> %d", num1,
			(num2 >> 24) & 0xff, (num2 >> 16) & 0xff, (num2 >> 8) & 0xff,
					(num2 >> 0) & 0xff, reg, (num2 ? 0 : 1));
}

void	debug_11_14_15(t_cursor *temp, unsigned num, t_debug *deb)
{
	if (num == 11)
	{
		num = get_direct(deb->field, looped(temp->pc, 1), 0) % IDX_MOD;
		ft_printf("created new cursor by fork at %d steps in %u pc",
				num, looped(temp->pc, num));
	}
	else if (num == 14)
	{
		num = get_direct(deb->field, looped(temp->pc, 1), 0);
		ft_printf("created new cursor by lfork at %d steps in %u pc",
				num, looped(temp->pc, num));
	}
	else if (num == 15)
	{
		num = *(temp->registrs + deb->reg - 1);
		ft_printf("r%u (%d) \"%c\" print", deb->reg, num, num);
	}
	else
		ft_putstr(A22);
}
