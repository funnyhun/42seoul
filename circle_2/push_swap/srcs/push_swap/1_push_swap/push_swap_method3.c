/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:33:51 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:08:04 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_ps_info *info)
{
	ft_printf("rra\n");
	reverse_rotation(get_last_node(info->a));
}

void	rrb(t_ps_info *info)
{
	ft_printf("rrb\n");
	reverse_rotation(get_last_node(info->b));
}

void	rrr(t_ps_info *info)
{
	ft_printf("rrr\n");
	reverse_rotation(get_last_node(info->a));
	reverse_rotation(get_last_node(info->b));
}
