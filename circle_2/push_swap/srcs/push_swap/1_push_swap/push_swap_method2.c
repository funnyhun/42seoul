/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:33:51 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:08:01 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_ps_info *info)
{
	ft_printf("ra\n");
	rotation(info->a);
}

void	rb(t_ps_info *info)
{
	ft_printf("rb\n");
	rotation(info->b);
}

void	rr(t_ps_info *info)
{
	ft_printf("rr\n");
	rotation(info->a);
	rotation(info->b);
}
