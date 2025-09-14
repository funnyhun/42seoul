/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:54:54 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:08:29 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_b	check_sorted(t_ps_info *info, int total)
{
	t_n	*target;
	int	index;

	target = info->a;
	index = 0;
	while (index < total)
	{
		if (index != target->index)
			return (FALSE);
		target = target->next;
		index++;
	}
	return (TRUE);
}

void	sort(t_ps_info *info)
{
	if (info->total == 1 || check_sorted(info, info->total))
		return ;
	else if (info->total == 2)
		sort_2(info);
	else if (info->total == 3)
		sort_3(info);
	else if (info->total == 4)
		sort_4(info);
	else if (info->total == 5)
		sort_5(info);
	else
		sandglass_sort(info);
}
