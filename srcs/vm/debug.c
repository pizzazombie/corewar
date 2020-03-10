/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:14 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/07 16:57:18 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		debug_action(t_cursor *temp, unsigned num, t_debug *deb)
{
	ft_putstr(A27);
	if (deb->num == 10)
		debug10(temp, deb);
	else if (num == 3)
		debug_reg(temp, '+', deb);
	else if (num == 4)
		debug_reg(temp, '-', deb);
	else if (num == 5 || num == 6 || num == 7)
		debug_567(temp, deb);
	else if (num == 9 || num == 13)
		debug_9_13(temp, deb);
	else if (num == 12)
		debug_12(temp, deb);
	else if (num == 8)
		debug_8(temp, deb);
	else if (num == 1)
		debug_1(temp, deb);
	else if (num == 2)
		debug_2(temp, deb);
	else
		debug_11_14_15(temp, num, deb);
	ft_putstr(A21);
}

void		debug(t_crwr *crwr, t_cursor *temp, unsigned num)
{
	unsigned char	arg;
	unsigned		pc;
	t_debug			deb;

	if (crwr->nbr_cycles < 0 || (int)crwr->arena->cycles >= crwr->nbr_cycles)
	{
		debug_general_info(crwr->arena, temp, num);
		arg = (g_op_tab[num].args_exists ? \
		*((unsigned char*)crwr->arena->field + looped(temp->pc, 1)) : 0x80);
		pc = looped(temp->pc, (g_op_tab[num].args_exists ? 2 : 1));
		debug_arg(arg, pc, num);
		ft_putstr(A10);
		pc = (g_op_tab[num].args_exists ? looped(temp->pc, 2) : \
												looped(temp->pc, 1));
		debug_arg_value(arg, pc, num, crwr->arena);
		deb.field = (unsigned char *)crwr->arena->field;
		deb.arg = *(deb.field + looped(temp->pc, 1));
		deb.reg = *(deb.field + looped(temp->pc, 2));
		deb.num = num;
		debug_action(temp, num, &deb);
		ft_putstr(A30);
		if (crwr->opt & 0x06 && !(crwr->opt & 0x01))
			while (getchar() != '\n')
				;
	}
}
