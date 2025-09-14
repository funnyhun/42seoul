/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:41:09 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:57:15 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	init_info(t_ps_info *info)
{
	info->a = NULL;
	info->b = NULL;
	info->chunk = 0;
	info->errno = OK;
	info->total = 0;
	info->min = 0;
}

int	main(int argc, char **argv)
{
	t_ps_info	info;

	if (argc < 2)
		return (0);
	init_info(&info);
	parsing(&info, ++argv);
	indexing(&info);
	sort(&info);
	delete_list(&info);
	exit(0);
	return (0);
}
