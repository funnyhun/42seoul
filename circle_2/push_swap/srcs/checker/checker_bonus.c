/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:03:04 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 12:46:08 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker_bonus.h"
#include "includes/push_swap_errno.h"

static void	init_info(t_ps_info *info)
{
	info->a = NULL;
	info->b = NULL;
	info->chunk = 0;
	info->errno = OK;
	info->total = 0;
	info->min = 0;
}

static t_b	process_command(t_ps_info *info, char *command)
{
	if (!ft_strncmp(command, "pa\n", 4))
		pa(info);
	else if (!ft_strncmp(command, "pb\n", 4))
		pb(info);
	else if (!ft_strncmp(command, "sa\n", 4))
		sa(info);
	else if (!ft_strncmp(command, "sb\n", 4))
		sb(info);
	else if (!ft_strncmp(command, "ss\n", 4))
		ss(info);
	else if (!ft_strncmp(command, "ra\n", 4))
		ra(info);
	else if (!ft_strncmp(command, "rb\n", 4))
		rb(info);
	else if (!ft_strncmp(command, "rr\n", 4))
		rr(info);
	else if (!ft_strncmp(command, "rra\n", 5))
		rra(info);
	else if (!ft_strncmp(command, "rrb\n", 5))
		rrb(info);
	else if (!ft_strncmp(command, "rrr\n", 5))
		rrr(info);
	else
		return (FALSE);
	return (TRUE);
}

static void	check_sorted(t_ps_info *info, int total)
{
	t_n	*target;
	int	index;

	target = info->a;
	index = 0;
	while (index < total)
	{
		if (index != target->index)
		{
			ft_printf("KO\n");
			delete_list(info);
			return ;
		}
		target = target->next;
		index++;
	}
	ft_printf("OK\n");
	delete_list(info);
}

int	main(int ac, char **av)
{
	t_ps_info	info;
	char		*command;

	if (ac < 2)
		return (0);
	init_info(&info);
	parsing(&info, ++av);
	indexing(&info);
	while (1)
	{
		command = get_next_line(STDIN_FILENO);
		if (!command)
			break ;
		if (!process_command(&info, command))
		{
			free(command);
			exit_err(&info, INVALID);
		}
		free(command);
	}
	check_sorted(&info, info.total);
	exit(0);
	return (0);
}
