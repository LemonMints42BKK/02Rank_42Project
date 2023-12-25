/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:25:52 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/18 00:07:26 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bigstack(t_list **top_one, t_list **top_zero, int numbers)
{
	static int	i = 0;

	if (i == 32)
		exit(-1);
	while (numbers-- > 0)
	{
		if (!is_empty(top_one))
		{
			if ((((*top_one)->range) >> i & 1) == 1)
				ra_rb("ra", top_one);
			else if ((((*top_one)->range) >> i & 1) == 0)
				pa_pb("pb", top_zero, top_one);
		}
	}
	i++;
}

void	sort_smallstack(t_list **top_a, t_list **top_b, int num)
{
	if (num == 2)
		sa_sb("sa", top_a);
	else if (num < 4)
		sort_three(top_a);
	else if (num == 4 || num == 5)
		sort_five(top_a, top_b, num);
	else
		insertion(top_a, top_b);
}

void	sort_step(t_list **top_a, t_list **top_b, int numbers)
{	
	while (!is_sorted(top_a, cmp_less_than))
	{
		if (numbers <= 15)
			sort_smallstack(top_a, top_b, numbers);
		else
			sort_bigstack(top_a, top_b, numbers);
		while (!(is_empty(top_b)))
			pa_pb("pa", top_a, top_b);
	}
}

void	implement(char **str_arg, int numbers)
{
	t_list	*top_a;
	t_list	*top_b;
	int		*tab;

	tab = NULL;
	tab = range(numbers, str_arg);
	top_a = init_to_stack(numbers, str_arg, tab);
	top_b = init_to_stack(0, str_arg, tab);
	sort_step(&top_a, &top_b, numbers);
	while (!is_empty(&top_a))
		free(pop(&top_a));
	free(tab);
}

int	main(int argc, char **argv)
{
	char	**str_arg;
	int		numbers;
	int		i;

	i = 0;
	numbers = 0;
	str_arg = NULL;
	if (argc < 2 || (argc == 2 && ft_strlen(argv[1]) == 0))
		return (0);
	str_arg = renew_arg(argv, &numbers);
	if (non_case_error(numbers, str_arg))
	{
		implement(str_arg, numbers);
		i = 0;
		while (str_arg[i])
			free(str_arg[i++]);
		free(str_arg);
	}
	return (0);
}
