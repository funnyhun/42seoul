/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:33:51 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 12:01:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ra(t_ps_info *info)
{
	rotation(info->a);
}

void	rb(t_ps_info *info)
{
	rotation(info->b);
}

void	rr(t_ps_info *info)
{
	rotation(info->a);
	rotation(info->b);
}
