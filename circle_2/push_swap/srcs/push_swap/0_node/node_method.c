/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:23:15 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:07:48 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_n **src, t_n **dst)
{
	if (!*src)
		return ;
	if (*dst)
	{
		(*dst)->pre = *src;
		*src = (*src)->next;
		(*dst)->pre->next = *dst;
		*dst = (*dst)->pre;
		if (*src)
			(*src)->pre = NULL;
	}
	else
	{
		*dst = *src;
		*src = (*src)->next;
		if (*src)
			(*src)->pre = NULL;
		(*dst)->next = NULL;
	}
}

void	swap(t_n *src)
{
	int	temp;

	if (!src || !src->next)
		return ;
	temp = src->index;
	src->index = src->next->index;
	src->next->index = temp;
}

void	rotation(t_n *src)
{
	int	temp;

	if (!src || !src->next)
		return ;
	temp = src->index;
	while (src->next)
	{
		src->index = src->next->index;
		src = src->next;
	}
	src->index = temp;
}

void	reverse_rotation(t_n *src)
{
	int	temp;

	if (!src || !src->pre)
		return ;
	temp = src->index;
	while (src->pre)
	{
		src->index = src->pre->index;
		src = src->pre;
	}
	src->index = temp;
}
