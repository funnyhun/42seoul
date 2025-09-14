/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:33:51 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:07:58 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_ps_info *info)
{
	ft_printf("pa\n");
	push(&info->b, &info->a);
}

void	pb(t_ps_info *info)
{
	ft_printf("pb\n");
	push(&info->a, &info->b);
}

void	sa(t_ps_info *info)
{
	ft_printf("sa\n");
	swap(info->a);
}

void	sb(t_ps_info *info)
{
	ft_printf("sb\n");
	swap(info->b);
}

void	ss(t_ps_info *info)
{
	ft_printf("ss\n");
	swap(info->a);
	swap(info->b);
}
