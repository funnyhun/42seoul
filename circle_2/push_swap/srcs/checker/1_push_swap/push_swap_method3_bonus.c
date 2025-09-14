/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:33:51 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 12:01:27 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	rra(t_ps_info *info)
{
	reverse_rotation(get_last_node(info->a));
}

void	rrb(t_ps_info *info)
{
	reverse_rotation(get_last_node(info->b));
}

void	rrr(t_ps_info *info)
{
	reverse_rotation(get_last_node(info->a));
	reverse_rotation(get_last_node(info->b));
}
