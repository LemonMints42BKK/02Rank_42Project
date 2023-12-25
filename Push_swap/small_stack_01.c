/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:45:30 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/17 23:47:42 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_point(t_list **top_a)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	b = *top_a;
	b = b->next;
	a = b->prev;
	c = b->next;
	if (a->range == 1 && c->range == 2)
		sa_sb("sa", top_a);
	if (a->range == 2 && c->range == 0)
		sa_sb("sa", top_a);
	if (a->range == 0 && c->range == 1)
		sa_sb("sa", top_a);
	if (a->range == 1 && c->range == 0)
		rra_rrb("rra", top_a);
	if (a->range == 2 && c->range == 1)
		ra_rb("ra", top_a);
}

void	sort_three(t_list **top_a)
{
	while (!is_sorted(top_a, cmp_less_than))
		check_point(top_a);
}

int	find_index(t_list **top_a, int numbers, int range)
{
	int		i;
	t_list	*min;

	i = 0;
	min = *top_a;
	while (i++ < numbers)
	{
		if (min->range == range)
			break ;
		min = min->next;
	}
	i--;
	return (i);
}

void	choose_index(t_list **top_a, t_list **top_b, int i, int numbers)
{
	if (i == 1)
		sa_sb("sa", top_a);
	if (i == 2)
	{
		ra_rb("ra", top_a);
		ra_rb("ra", top_a);
	}
	if (i == 3)
	{
		if (numbers == 5)
			rra_rrb ("rra", top_a);
		rra_rrb ("rra", top_a);
	}
	if (i == 4)
		rra_rrb ("rra", top_a);
	pa_pb("pb", top_b, top_a);
}

void	sort_five(t_list **top_a, t_list **top_b, int numbers)
{
	int	i;
	int	range;

	range = 3;
	while (numbers > 3)
	{
		i = find_index(top_a, numbers, range);
		choose_index(top_a, top_b, i, numbers);
		range = 4;
		numbers = count_data_stack(top_a);
	}
	sort_three(top_a);
	pa_pb("pa", top_a, top_b);
	pa_pb("pa", top_a, top_b);
	ra_rb("ra", top_a);
	ra_rb("ra", top_a);
}
