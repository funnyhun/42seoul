/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:33:51 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 12:01:13 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	pa(t_ps_info *info)
{
	push(&info->b, &info->a);
}

void	pb(t_ps_info *info)
{
	push(&info->a, &info->b);
}

void	sa(t_ps_info *info)
{
	swap(info->a);
}

void	sb(t_ps_info *info)
{
	swap(info->b);
}

void	ss(t_ps_info *info)
{
	swap(info->a);
	swap(info->b);
}
