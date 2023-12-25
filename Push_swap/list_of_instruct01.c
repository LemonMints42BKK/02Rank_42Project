/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_of_instruct01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:07:55 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/15 02:37:56 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_pb(char *instr, t_list **top_dst, t_list **top_src)
{
	t_list	*temp;

	temp = pop(&(*top_src));
	push(&(*top_dst), temp->data, temp->range);
	free(temp);
	temp = NULL;
	ft_printf("%s\n", instr);
}

void	sa_sb(char *instr, t_list **top_dst)
{
	t_list	*newp;
	t_list	*ptr;

	if (is_empty(top_dst) || (*top_dst)->next == NULL)
		exit(1);
	newp = (*top_dst);
	(*top_dst) = newp->next;
	if ((*top_dst)->next != NULL)
	{
		ptr = (*top_dst)->next;
		newp->next = ptr;
		ptr->prev = newp;
	}
	else
		newp->next = NULL;
	(*top_dst)->next = newp;
	newp->prev = (*top_dst);
	(*top_dst)->prev = NULL;
	newp = NULL;
	ptr = NULL;
	if (!ft_strcmp(instr, ""))
		ft_printf("%s\n", instr);
}

void	ss(t_list **top_a1, t_list **top_b1)
{
	sa_sb("", &(*top_a1));
	sa_sb("", &(*top_b1));
	ft_printf(("ss\n"));
}

void	ra_rb(char *instr, t_list **top_dst)
{
	t_list	*ptr_tail;
	t_list	*temp;

	ptr_tail = *top_dst;
	while (ptr_tail->next != NULL)
		ptr_tail = ptr_tail->next;
	temp = pop(&(*top_dst));
	ptr_tail->next = temp;
	temp->prev = ptr_tail;
	temp->next = NULL;
	ptr_tail = NULL;
	if (!ft_strcmp(instr, ""))
		ft_printf("%s\n", instr);
}

void	rr(t_list **top_a1, t_list **top_b1)
{
	ra_rb("", &(*top_a1));
	ra_rb("", &(*top_b1));
	ft_printf("rr\n");
}
