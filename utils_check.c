/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:07:17 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/07 08:44:50 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(const char *str)
{
	int			i;
	int			t;
	long long	x;

	t = 1;
	i = 0;
	if (str[0] == 0)
		return (0);
	if (check_syntax(str) == 0)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+' || str[i] == ' ')
		if (str[i++] == '-')
			t = -1;
	x = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = (x * 10) + (str[i++] - '0');
		if ((x * t > 2147483647) || (x * t < -2147483648))
			return (0);
	}
	if (x == 0 && is_special_char(str) == 0)
		return (0);
	return (1);
}

int	check_signs(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			j = 0;
		if (j > 1)
			return (0);
		if (j == 1 && (str[0] != '+' || str[0] != '-'))
			return (0);
		if (str[i] == '-' || str[i] == '+')
			j++;
		i++;
	}
	return (1);
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_num(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	freeing(t_list **bluepill, t_list **redpill)
{
	t_list	*tmp;

	while (*bluepill != NULL)
	{
		tmp = *bluepill;
		*bluepill = (*bluepill)->next;
		free(tmp);
	}
	while (*redpill != NULL)
	{
		tmp = *redpill;
		*redpill = (*redpill)->next;
		free(tmp);
	}
	if (*bluepill)
		free(*bluepill);
	if (*redpill)
		free(*redpill);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}
