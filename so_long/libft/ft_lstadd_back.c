/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:03:01 by pnopjira          #+#    #+#             */
/*   Updated: 2022/04/04 07:04:31 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstlast;

	lstlast = ft_lstlast(*lst);
	if (lstlast == NULL)
	{
		*lst = new;
		return ;
	}
	lstlast->next = new;
}
