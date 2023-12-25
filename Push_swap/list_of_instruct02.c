/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_of_instruct02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:08:50 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/14 23:11:24 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(char *instr, t_list **top_dst)
{
	t_list	*ptr_tail;
	t_list	*ptr;

	ptr_tail = *top_dst;
	while (ptr_tail->next != NULL)
		ptr_tail = ptr_tail->next;
	ptr = ptr_tail->prev;
	ptr->next = NULL;
	ptr = NULL;
	ptr_tail->next = *top_dst;
	(*top_dst)->prev = ptr_tail;
	*top_dst = ptr_tail;
	ptr_tail = NULL;
	if (!ft_strcmp(instr, ""))
		ft_printf("%s\n", instr);
}

void	rrr(t_list **top_a, t_list **top_b)
{
	rra_rrb("", &(*top_a));
	rra_rrb("", &(*top_b));
	ft_printf(("rrr\n"));
}
