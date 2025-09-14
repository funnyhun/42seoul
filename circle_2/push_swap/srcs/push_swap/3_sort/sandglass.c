/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandglass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:25:03 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:08:23 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	init_chunk(t_ps_info *info)
{
	if (info->total < 25)
		return (14);
	else if (info->total <= 50)
		return (15);
	else if (info->total <= 150)
		return (17);
	else if (info->total <= 200)
		return (20);
	else if (info->total <= 250)
		return (22);
	else if (info->total <= 300)
		return (23);
	else if (info->total <= 400)
		return (26);
	else if (info->total <= 450)
		return (28);
	else
		return (31);
}

void	sandglass_sort(t_ps_info *info)
{
	info->chunk = init_chunk(info);
	a_to_b(info);
	info->min--;
	b_to_a(info);
}
