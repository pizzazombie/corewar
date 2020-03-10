/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:09:26 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/07 17:14:17 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "struct.h"

int					ft_error(char *msg, int err);

void				valid_command(int ac, char **av, t_crwr **crwr);
void				fix_created_players(int ac, char **av, t_players *players, \
																	int count);
int					ft_is_int(char *str);
unsigned			ft_players_count(t_players *list);

void				valid_files(t_players *players);

t_cursor			*fill_arena(t_crwr *crwr, unsigned i);
t_arena				*init_arena(char alive);

t_cursor			*ft_cursor_new(unsigned id, unsigned count_pl);
t_cursor			*ft_cursor_fork(t_cursor *temp, unsigned pc, unsigned id);
t_cursor			*ft_cursor_del(t_cursor **cursor, t_cursor **temp);
void				ft_cursor_add(t_cursor **cursor, t_cursor *new);

unsigned			looped(int num1, int num2);
int					get_direct(void *arena, unsigned pc, char size_four);
int					get_indirect(void *arena, unsigned pc, unsigned cur_pc);

t_name				*free_players(t_crwr **crwr);
void				check(t_arena *arena, t_cursor **cursor);
void				arena(t_crwr *crwr, t_arena *arena);
void				cycle(t_crwr *crwr);

void				live(t_crwr *crwr, t_cursor *temp);
void				ld(t_crwr *crwr, t_cursor *temp);
void				lld(t_crwr *crwr, t_cursor *temp);
void				st(t_crwr *crwr, t_cursor *temp);
void				sti(t_crwr *crwr, t_cursor *temp);
void				add(t_crwr *crwr, t_cursor *temp);
void				sub(t_crwr *crwr, t_cursor *temp);
void				and(t_crwr *crwr, t_cursor *temp);
void				or(t_crwr *crwr, t_cursor *temp);
void				xor(t_crwr *crwr, t_cursor *temp);
void				zjmp(t_crwr *crwr, t_cursor *temp);
void				aff(t_crwr *crwr, t_cursor *temp);
void				cfork(t_crwr *crwr, t_cursor *temp);
void				lfork(t_crwr *crwr, t_cursor *temp);
void				ldi(t_crwr *crwr, t_cursor *temp);
void				lldi(t_crwr *crwr, t_cursor *temp);

void				free_all(t_crwr *crwr);

t_visu				*get_visu(t_crwr *crwr);
unsigned			get_arena_pair(unsigned char ch);
unsigned			get_arena_attr(unsigned char ch);
unsigned			count_of_cursor(t_cursor *cursor);
void				get_key(t_visu *visu);
void				draw_box(unsigned line, unsigned column, \
													unsigned y, unsigned x);
void				print_visu_buy(char *str, unsigned y, unsigned x, \
																unsigned len);
void				visu_arena(t_crwr *crwr, t_arena *arena, t_visu *visu);
void				visu_update(t_crwr *crwr);
void				get_visu_windows(t_arena *arena, t_cursor *cursor, \
																t_visu *visu);

void				debug(t_crwr *crwr, t_cursor *temp, unsigned num);
void				debug_action(t_cursor *temp, unsigned num, t_debug *deb);
void				debug10(t_cursor *temp, t_debug *deb);
int					debug10_num1(t_cursor *temp, t_debug *deb, int num);
int					debug10_num2(t_cursor *temp, t_debug *deb, int num, \
																	int num1);
void				debug_567(t_cursor *temp, t_debug *deb);
int					debug_80_40(t_cursor *temp, char *s, t_debug *deb);
int					debug_20_10(t_cursor *temp, t_debug *deb);
int					debug_idx_mod(t_cursor *temp, t_debug *deb);
void				debug_reg(t_cursor *temp, char c, t_debug *deb);
int					debug_80_40_pc(t_cursor *temp, t_debug *deb);
void				debug_9_13(t_cursor *temp, t_debug *deb);
void				debug_1(t_cursor *temp, t_debug *deb);
void				debug_2(t_cursor *temp, t_debug *deb);
void				debug_12(t_cursor *temp, t_debug *deb);
void				debug_8(t_cursor *temp, t_debug *deb);
void				debug_general_info(t_arena *arena, t_cursor *temp, \
																unsigned num);
void				debug_arg(unsigned char arg, unsigned pc, unsigned num);
void				debug_arg2(unsigned char code, unsigned num, unsigned *pc);
void				debug_arg_value(unsigned char arg, unsigned pc, \
												unsigned num, t_arena *arena);
void				debug_arg_value2(unsigned char code, unsigned num, \
												unsigned *pc, t_arena *arena);
void				debug_11_14_15(t_cursor *temp, unsigned num, t_debug *deb);

#endif
