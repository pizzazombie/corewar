/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:14 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/10 14:02:29 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		debug_idx_mod(t_cursor *temp, t_debug *deb)
{
	int				num2;
	unsigned char	reg;

	if (deb->arg & 0x10)
	{
		reg = *(deb->field + deb->pc);
		num2 = *(temp->registrs + reg - 1);
		ft_printf(" r%u (%d)) %% IDX_MOD) = ", reg, num2);
		deb->pc = looped(deb->pc, 1);
	}
	else
	{
		num2 = get_direct(deb->field, deb->pc, 0);
		ft_printf(" %d) %% IDX_MOD) = ", num2);
		deb->pc = looped(deb->pc, 2);
	}
	return (num2);
}

void	debug_reg(t_cursor *temp, char c, t_debug *deb)
{
	int				num1;
	int				num2;
	int				buf;
	unsigned char	r;

	r = *(deb->field + looped(temp->pc, 2));
	num1 = *(temp->registrs + r - 1);
	ft_printf("r%u (%d) %c ", r, num1, c);
	r = *(deb->field + looped(temp->pc, 3));
	num2 = *(temp->registrs + r - 1);
	ft_printf("r%u (%d) -> ", r, num2);
	r = *(deb->field + looped(temp->pc, 4));
	buf = c == '+' ? num1 + num2 : num1 - num2;
	ft_printf("r%u = %d + carry -> %d", r, buf, (buf ? 0 : 1));
}

void	debug_general_info(t_arena *arena, t_cursor *temp, unsigned num)
{
	size_t i;

	ft_printf(A1"%u"A21, arena->cycles);
	ft_printf(A5"%u"A21, temp->id & 0x7ffffff);
	ft_printf(A2"%u"A21, arena->alive);
	ft_printf(A3"%u"A21, arena->nbr_live);
	ft_printf(A4"%d"A21, arena->cycles_to_die);
	ft_printf(A6"%u"A21, temp->pc);
	ft_printf(A7"%u"A21, temp->last_live);
	ft_printf(A8);
	i = 0;
	while (i != REG_NUMBER)
	{
		ft_printf("%d ", *(temp->registrs + i));
		i++;
	}
	ft_putstr(A21);
	ft_printf(A9"%s"A21, g_op_tab[num].name);
	ft_putstr(A10);
}
