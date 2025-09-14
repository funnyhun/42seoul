/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:02:03 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:08:16 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_b	is_closer_top(t_ps_info *info)
{
	t_n	*dst;
	int	cmd;

	dst = info->a;
	cmd = 0;
	while (cmd <= (info->total - info->min) / 2)
	{
		if (dst->index <= info->min + info->chunk)
			return (TRUE);
		dst = dst->next;
		cmd++;
	}
	return (FALSE);
}

static void	a_rotate_closer(t_b is_closer_top, t_ps_info *info)
{
	while (info->a->index > info->min + info->chunk)
	{
		if (is_closer_top == TRUE)
			ra(info);
		else
			rra(info);
	}
}

void	a_to_b(t_ps_info *info)
{
	while (info->a)
	{
		if (info->a->index <= info->min)
		{
			pb(info);
			info->min++;
		}
		else if (info->a->index > info->min
			&& info->a->index <= info->min + info->chunk)
		{
			pb(info);
			if (is_closer_top(info) && info->a->index > info->min + info->chunk)
				rr(info);
			else if (info->b->next)
				rb(info);
			info->min++;
		}
		else
			a_rotate_closer(is_closer_top(info), info);
	}
}
