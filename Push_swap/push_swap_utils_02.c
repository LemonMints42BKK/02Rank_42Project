/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:19:11 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/17 20:51:03 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++ != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	os;

	os = 0;
	if (!src)
		return (0);
	while ((os + 1) < dstsize && src[os] != '\0')
	{
		dst[os] = src[os];
		os++;
	}
	if (dstsize > 0)
		dst[os] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(str, s1, s1_len + 1);
		free((void *)s1);
		s1 = NULL;
	}
	if (s2)
		ft_strlcpy(&str[s1_len], s2, s2_len + 1);
	return (str);
}

char	*collect_strn(char **argv)
{
	char	*strn;
	int		i;

	strn = NULL;
	i = 1;
	while (argv[i])
	{
		strn = ft_strjoin(strn, argv[i]);
		strn = ft_strjoin(strn, " ");
		i++;
	}
	return (strn);
}

char	**renew_arg(char **argv, int *numbers)
{
	char	*strn;
	char	**str_arg;
	int		i;

	i = 0;
	check_sp_eof(argv);
	strn = collect_strn(argv);
	str_arg = ft_split(strn, ' ');
	free(strn);
	strn = NULL;
	while (str_arg[i++])
		*numbers += 1;
	return (str_arg);
}
