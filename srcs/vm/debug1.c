/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:14 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/10 14:02:57 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	debug_1(t_cursor *temp, t_debug *deb)
{
	int num;

	deb->arg = *(deb->field + looped(temp->pc, 1));
	if (deb->arg & 0x40)
		num = get_indirect(deb->field, looped(temp->pc, 2), temp->pc);
	else
		num = get_direct(deb->field, looped(temp->pc, 2), 1);
	deb->reg = *(deb->field + looped(temp->pc, (deb->arg & 0x40 ? 4 : 6)));
	ft_printf("%d -> r%u + carry -> %d", num, deb->reg, (num ? 0 : 1));
}

void	debug_2(t_cursor *temp, t_debug *deb)
{
	int num;

	num = *(temp->registrs + deb->reg - 1);
	if (deb->arg & 0x20)
	{
		ft_printf("r%u (%02x%02x%02x%02x) -> ", deb->reg, (num >> 24) & 0xff,
				(num >> 16) & 0xff, (num >> 8) & 0xff, (num >> 0) & 0xff);
		num = get_direct(deb->field,
				looped(temp->pc, 3), 0) % IDX_MOD;
		ft_printf("at %d steps \"%02x%02x%02x%02x\"", num,
			*(deb->field + looped(temp->pc, num + 0)),
				*(deb->field + looped(temp->pc, num + 1)),
						*(deb->field + looped(temp->pc, num + 2)),
								*(deb->field + looped(temp->pc, num + 3)));
	}
	else
	{
		ft_printf("r%u (%d) -> ", deb->reg, num);
		deb->reg = *(deb->field + looped(temp->pc, 3));
		ft_printf("r%u", deb->reg);
	}
}

void	debug_12(t_cursor *temp, t_debug *deb)
{
	int num;

	deb->arg = *(deb->field + looped(temp->pc, 1));
	if (deb->arg & 0x40)
	{
		num = get_direct(deb->field, looped(temp->pc, 2), 0);
		num = get_direct(deb->field, looped(temp->pc, num), 1);
	}
	else
		num = get_direct(deb->field, looped(temp->pc, 2), 1);
	deb->reg = *(deb->field + looped(temp->pc, (deb->arg & 0x40 ? 4 : 6)));
	ft_printf("%d -> r%u + carry -> %d", num, deb->reg, (num ? 0 : 1));
}

void	debug_8(t_cursor *temp, t_debug *deb)
{
	int num;

	if (temp->id & 0x80000000)
	{
		num = get_direct(deb->field, looped(temp->pc, 1), 0) % IDX_MOD;
		ft_printf("Jumping at %02x%02x (%d) steps -> %u pc", *(deb->field +
				looped(temp->pc, 1)), *(deb->field + looped(temp->pc, 2)),
						num, looped(temp->pc, num));
	}
	else
		ft_printf("Not jump. pc(%u)->new_pc(%u)", temp->pc, \
													looped(temp->pc, 3));
}

void	debug_567(t_cursor *temp, t_debug *deb)
{
	int				num1;
	int				num2;
	int				buf;

	if (deb->num == '5')
		num1 = debug_80_40(temp, "AND", deb);
	else
		num1 = deb->num == '6' ? debug_80_40(temp, "OR", deb)
				: debug_80_40(temp, "XOR", deb);
	num2 = debug_20_10(temp, deb);
	if (deb->num == '5')
		buf = num1 & num2;
	else
		buf = deb->num == '6' ? num1 | num2 : num1 ^ num2;
	deb->arg = *(deb->field + deb->pc);
	ft_printf(" -> r%u = %d + carry -> %d", deb->arg, buf, (buf ? 0 : 1));
}
