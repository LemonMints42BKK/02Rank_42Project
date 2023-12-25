/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_imprementation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:21:09 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/17 12:12:15 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **top, int data, int i)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		temp = NULL;
	temp->prev = NULL;
	temp->data = data;
	temp->range = i;
	temp->next = NULL;
	if (*top != NULL)
	{
		temp->next = *top;
		(*top)->prev = temp;
	}
	*top = temp;
	temp = NULL;
}

int	is_empty(t_list **top)
{
	if (*top == NULL)
		return (1);
	else
		return (0);
}

t_list	*pop(t_list **top)
{
	t_list	*keep;

	if (is_empty(top))
		return (NULL);
	keep = *top;
	if ((*top)->next != NULL)
	{
		*top = (*top)->next;
		(*top)->prev = NULL;
	}
	else
		*top = NULL;
	return (keep);
}

t_list	*init_to_stack(int members, char **data, int *tab)
{
	t_list	*head;
	int		var;
	int		n;
	int		i;

	head = NULL;
	n = members;
	while (n > 0)
	{
		var = ft_atoi(data[--n]);
		i = 0;
		while (i < members)
		{
			if (var == tab[i])
				break ;
			i++;
		}
		push(&head, var, i);
	}
	tab = NULL;
	return (head);
}
