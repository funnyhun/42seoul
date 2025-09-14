/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:23:23 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:08:26 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_ps_info *info)
{
	if (info->a->index < info->a->next->index)
		return ;
	sa(info);
}

void	sort_3(t_ps_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->a->index;
	b = info->a->next->index;
	c = info->a->next->next->index;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa(info);
		ra(info);
	}
	else if (b < a && a < c)
		sa(info);
	else if (b < c && c < a)
		ra(info);
	else if (c < a && a < b)
		rra(info);
	else if (c < b && b < a)
	{
		sa(info);
		rra(info);
	}
}

static t_b	is_closer_top(t_ps_info *info)
{
	t_n	*dst;
	int	cmd;

	dst = info->a;
	cmd = 0;
	while (cmd <= info->total / 2)
	{
		if (dst->index == info->min)
			return (TRUE);
		dst = dst->next;
		cmd++;
	}
	return (FALSE);
}

void	sort_4(t_ps_info *info)
{
	t_b	closer_to_top;

	closer_to_top = is_closer_top(info);
	while (info->a->index != info->min)
	{
		if (closer_to_top)
			ra(info);
		else
			rra(info);
	}
	pb(info);
	sort_3(info);
	pa(info);
}

void	sort_5(t_ps_info *info)
{
	t_b	closer_to_top;

	closer_to_top = is_closer_top(info);
	while (info->a->index != info->min)
	{
		if (closer_to_top)
			ra(info);
		else
			rra(info);
	}
	pb(info);
	info->min++;
	sort_4(info);
	pa(info);
}
