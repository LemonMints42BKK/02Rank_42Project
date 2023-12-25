/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:47:22 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/15 21:31:49 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *strn)
{
	int			sign;
	long int	base;
	int			i;

	sign = 1;
	base = 0;
	i = 0;
	while ((strn[i] >= 9 && strn[i] <= 13) || strn[i] == 32)
		i++;
	if (strn[i] == '-' || strn[i] == '+')
	{
		if (strn[i] == '-')
			sign = -1;
		i++;
	}
	while (strn[i] != '\0')
	{
		base = (base * 10) + (strn[i++] - '0');
	}
	return (sign * base);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (1);
		str1++;
		str2++;
	}
	return (0);
}

int	count_data_stack(t_list **top)
{
	t_list	*ptr;
	int		count;

	ptr = *top;
	count = 0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	print_stack(t_list **top_a, t_list **top_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_a = *top_a;
	ptr_b = *top_b;
	while (!is_empty(&ptr_a) || !is_empty(&ptr_b))
	{
		if (!is_empty(&ptr_a))
		{
			ft_printf("%d", ptr_a->data);
			ptr_a = ptr_a->next;
		}
		if (!is_empty(&ptr_b))
		{
			ft_printf("               %d", ptr_b->data);
			ptr_b = ptr_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("----------     ----------\na               b\n\n");
}
