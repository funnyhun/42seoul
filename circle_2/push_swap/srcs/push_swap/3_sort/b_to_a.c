/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:17:30 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:08:20 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_b	is_closer_top(t_ps_info *info)
{
	t_n	*dst;
	int	cmd;

	dst = info->b;
	cmd = 0;
	while (cmd <= info->min / 2)
	{
		if (dst->index == info->min)
			return (TRUE);
		dst = dst->next;
		cmd++;
	}
	return (FALSE);
}

void	b_to_a(t_ps_info *info)
{
	t_b	res;

	while (info->b)
	{
		if (info->b->index == info->min)
		{
			pa(info);
			info->min--;
		}
		else
		{
			res = is_closer_top(info);
			while (info->b->index != info->min)
			{
				if (res == TRUE)
					rb(info);
				else
					rrb(info);
			}
			res = FAIL;
		}
	}
}
