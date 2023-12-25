/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:21:06 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/15 10:16:26 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_sort_lst(t_list **key, t_list **u, t_list **s, int j)
{
	int	m;

	m = 0;
	while (cmp_greater_than(u, key))
	{
		sa_sb ("sa", u);
		if (!is_empty(s) && j != 0)
		{
			pa_pb("pa", u, s);
			j--;
			m++;
		}
	}
	while (m-- >= 0)
	{	
		pa_pb("pb", s, u);
		j++;
	}
	return (j);
}

void	insertion(t_list **u, t_list **s)
{
	t_list	*key;
	int		i;
	int		j;

	i = count_data_stack(u);
	j = 0;
	while (i-- > 1)
	{
		key = (*u)->next;
		j = to_sort_lst(&key, u, s, j);
	}
	while (j-- > 0)
		pa_pb("pa", u, s);
}
