/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_flags_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:44:44 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/07 11:47:57 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	pass_num(char *f, size_t c)
{
	while (is_num(f[c]))
		c++;
	return (c);
}

void	decode_flags(char *f, size_t c, int n, t_o *op)
{
	size_t	i;

	while (c < (size_t)n)
	{
		if (f[c] == '.' || (f[c] >= 49 && f[c] <= 57))
		{
			c = pass_num(f, c + 1);
			continue ;
		}
		i = 0;
		while (i < FLAGS_COUNT)
		{
			if (f[c] == FLAGS[i])
			{
				op->f[i] = TRUE;
				break ;
			}
			i++;
		}
		c++;
	}
}
