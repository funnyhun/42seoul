/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:14 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:07:51 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	delete_list(t_ps_info *info)
{
	t_n	*next;

	while (info->a)
	{
		next = info->a->next;
		ft_memset(info->a, 0, sizeof(t_n));
		free(info->a);
		info->a = next;
	}
	while (info->b)
	{
		next = info->b->next;
		ft_memset(info->b, 0, sizeof(t_n));
		free(info->b);
		info->b = next;
	}
}

t_n	*get_last_node(t_n *list)
{
	t_n	*node;

	if (!list)
		return (NULL);
	node = list;
	while (node->next)
		node = node->next;
	return (node);
}

void	new_node(t_ps_info *info, int index)
{
	t_n	*target;
	t_n	*new;

	target = get_last_node(info->a);
	new = ft_calloc(1, sizeof(t_n));
	if (!new)
		exit_err(info, OUT_OF_MEMORY);
	new->value = index;
	new->index = 0;
	new->next = NULL;
	new->pre = NULL;
	if (!target)
		info->a = new;
	else
	{
		target->next = new;
		new->pre = target;
	}
	info->total++;
}
