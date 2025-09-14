/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:05:01 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:08:07 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing(t_ps_info *info)
{
	t_n	*target;
	t_n	*cursor;

	target = info->a;
	while (target)
	{
		cursor = info->a;
		while (cursor)
		{
			if (target->value > cursor->value)
				target->index++;
			cursor = cursor->next;
		}
		target = target->next;
	}
}
