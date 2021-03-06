/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 04:48:45 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/31 05:56:00 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **bluepill)
{
	if ((*bluepill)->content > (*bluepill)->next->content)
		sa(*bluepill);
	if ((*bluepill)->content < (*bluepill)->next->content)
		return ;
}

void	sort_three_one(t_list **bluepill, t_struct *data)
{
	if (((*bluepill)->content > (*bluepill)->next->content)
		&& ((*bluepill)->next->content < (*bluepill)->next->next->content)
		&& ((*bluepill)->content < (*bluepill)->next->next->content))
	{
		sa(*bluepill);
		return ;
	}
	if (((*bluepill)->content > (*bluepill)->next->content)
		&& ((*bluepill)->next->content > (*bluepill)->next->next->content)
		&& ((*bluepill)->content > (*bluepill)->next->next->content))
	{
		sa(*bluepill);
		rra(bluepill, data);
		return ;
	}
	if (((*bluepill)->content > (*bluepill)->next->content)
		&& ((*bluepill)->next->content < (*bluepill)->next->next->content)
		&& ((*bluepill)->content > (*bluepill)->next->next->content))
	{
		ra(bluepill);
		return ;
	}
}

void	sort_three_two(t_list **bluepill, t_struct *data)
{
	if (((*bluepill)->content < (*bluepill)->next->content)
		&& ((*bluepill)->next->content > (*bluepill)->next->next->content)
		&& ((*bluepill)->content < (*bluepill)->next->next->content))
	{
		sa(*bluepill);
		ra(bluepill);
		return ;
	}
	if (((*bluepill)->content < (*bluepill)->next->content)
		&& ((*bluepill)->next->content > (*bluepill)->next->next->content)
		&& ((*bluepill)->content > (*bluepill)->next->next->content))
	{
		rra(bluepill, data);
		return ;
	}
}

void	method_one(t_list *bluepill, t_struct *data)
{
	data->nb_one = 0;
	while (bluepill != NULL && bluepill->content < data->to_order)
	{
		data->nb_one++;
		bluepill = bluepill->next;
	}
}

void	apply_one(t_list **bluepill, t_list **redpill, t_struct *data)
{
	int	i;

	i = 0;
	while (i < data->nb_one)
	{
		ra(bluepill);
		i++;
	}
	if (pa(bluepill, redpill) == 0)
		return ;
	i = 0;
	while (i < data->nb_one)
	{
		rra(bluepill, data);
		i++;
	}
}
