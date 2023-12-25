/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:39:13 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/17 23:20:41 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include <string.h>

typedef struct s_list
{
	struct s_list	*prev;
	struct s_list	*next;
	int				data;
	int				range;
}t_list;

void		print_stack(t_list **top_a, t_list **top_b);
void		push(t_list **top, int data, int i);
int			is_empty(t_list **top);
t_list		*pop(t_list **top);
t_list		*init_to_stack(int members, char **data, int *tab);
long int	ft_atoi(const char *strn);
int			ft_strcmp(const char *str1, const char *str2);
char		*collect_strn(char **argv);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(const char *s1, const char *s2);
char		**ft_split(const char *s, char c);
int			count_data_stack(t_list **top);
void		ft_swap(int *a, int *b);
void		ft_putstr_fd(char *s, int fd);
int			ft_printf(const char *format, ...);
int			non_case_error(int numbers, char **data);
int			no_sp_no_eof(char *strn);
void		check_sp_eof(char **argv);
int			ft_isundup(t_list *top, int var);
size_t		ft_strlen(const char *s);
char		**renew_arg(char **argv, int *numbers);
int			*range(int numbers, char **argv);
void		pa_pb(char *instr, t_list **top_dst, t_list **top_src);
void		sa_sb(char *instr, t_list **top_dst);
void		ss(t_list **top_a1, t_list **top_b1);
void		ra_rb(char *instr, t_list **top_dst);
void		rr(t_list **top_a1, t_list **top_b1);
void		rra_rrb(char *instr, t_list **top_dst);
void		rrr(t_list **top_a, t_list **top_b);
int			cmp_less_than(t_list **ptr_a1, t_list **ptr_a2);
int			cmp_greater_than(t_list **ptr_a1, t_list **ptr_a2);
int			is_sorted(t_list **top, int cmp(t_list **data_1, t_list **data_2));
void		sort_three(t_list **top_a);
void		sort_five(t_list **top_a, t_list **top_b, int members);
void		insertion(t_list **a, t_list **b);

#endif
