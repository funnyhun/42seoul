/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_err_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:30:37 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 13:32:54 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	check(void)
{
	system("leaks check");
}

static char	*get_err_message(int errno)
{
	char	*err[ERRNO_LEN];

	err[OUT_OF_MEMORY] = "ERROR\nout of memory.. : ";
	err[NOT_DIGIT] = "ERROR\nis not DIGIT : ";
	err[NOT_INTEGER] = "ERROR\nis not INT.. : ";
	err[DUP_ARGV] = "ERROR\nis dup argv : ";
	err[INVALID] = "ERROR\ninvalid command : ";
	(void)errno;
	return ("Error\n");
}

void	exit_err(t_ps_info *info, int errno)
{
	(void)errno;
	delete_list(info);
	ft_putstr_fd(get_err_message(errno), STDERR_FILENO);
	exit(1);
}
