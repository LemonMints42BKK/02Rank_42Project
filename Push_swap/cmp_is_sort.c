/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_is_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:44:32 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/14 23:01:27 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp_less_than(t_list **ptr_a1, t_list **ptr_a2)
{
	return ((*ptr_a1)->range < (*ptr_a2)->range);
}

int	cmp_greater_than(t_list **ptr_a1, t_list **ptr_a2)
{
	return ((*ptr_a1)->range > (*ptr_a2)->range);
}

int	is_sorted(t_list **top, int cmp(t_list **data_1, t_list **data_2))
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *top;
	ptr2 = (*top)->next;
	while (ptr2 != NULL && ptr1 != NULL)
	{
		if (cmp(&ptr1, &ptr2))
		{
			ptr1 = ptr2;
			ptr2 = ptr2->next;
		}
		else
			return (0);
	}
	return (1);
}
