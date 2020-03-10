/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:14 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/10 13:59:05 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	debug_arg(unsigned char arg, unsigned pc, unsigned num)
{
	size_t			i;
	unsigned char	code;

	i = 0;
	while (i < g_op_tab[num].args)
	{
		code = (arg >> (6 - i * 2)) & 0x03;
		debug_arg2(code, num, &pc);
		if (i != 2)
			ft_putstr(A26);
		i++;
	}
	while (i != 3)
	{
		ft_putstr(A22);
		if (i != 2)
			ft_putstr(A26);
		i++;
	}
	ft_putstr(A21);
}

void	debug_arg2(unsigned char code, unsigned num, unsigned *pc)
{
	if (code == REG_CODE)
	{
		ft_putstr(A23);
		*pc = looped(*pc, 1);
	}
	else if (code == DIR_CODE)
	{
		ft_putstr(A24);
		*pc = (g_op_tab[num].dir_is_four ? looped(*pc, 2) :
				looped(*pc, DIR_SIZE));
	}
	else if (code == IND_CODE)
	{
		ft_putstr(A25);
		*pc = looped(*pc, IND_SIZE);
	}
	else
		ft_putstr(A22);
}

void	debug_arg_value(unsigned char arg, unsigned pc,
			unsigned num, t_arena *arena)
{
	size_t			i;
	unsigned char	code;

	i = 0;
	while (i < g_op_tab[num].args)
	{
		code = (arg >> (6 - i * 2)) & 0x03;
		debug_arg_value2(code, num, &pc, arena);
		if (i != 2)
			ft_putstr(A26);
		i++;
	}
	while (i != 3)
	{
		ft_putstr(A22);
		if (i != 2)
			ft_putstr(A26);
		i++;
	}
	ft_putstr(A21);
}

void	debug_arg_value2(unsigned char code, unsigned num,
		unsigned *pc, t_arena *arena)
{
	if (code == REG_CODE)
	{
		ft_printf("r%u", *((unsigned char *)arena->field + *pc));
		*pc = looped(*pc, 1);
	}
	else if (code == DIR_CODE)
	{
		ft_printf("%02x%02x", *((unsigned char *)arena->field + looped(*pc, 0)),
				*((unsigned char *)arena->field + looped(*pc, 1)));
		if (!g_op_tab[num].dir_is_four)
			ft_printf("%02x%02x", *((unsigned char *)arena->field + looped(*pc,
					2)), *((unsigned char *)arena->field + looped(*pc, 3)));
		*pc = (g_op_tab[num].dir_is_four ? looped(*pc, 2) :
				looped(*pc, DIR_SIZE));
	}
	else if (code == IND_CODE)
	{
		ft_printf("%02x%02x", *((unsigned char *)arena->field + looped(*pc, 0)),
					*((unsigned char *)arena->field + looped(*pc, 1)));
		*pc = looped(*pc, IND_SIZE);
	}
	else
		ft_putstr(A22);
}
