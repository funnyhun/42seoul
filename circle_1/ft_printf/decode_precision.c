/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:45:53 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/30 14:13:12 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cal_precision(char *f, size_t c, int *p)
{
	while (is_num(f[c]))
	{
		*p = *p * 10;
		*p += f[c] - 48;
		c++;
	}
	return (c);
}

int	apply_precision(int *p, t_o *op)
{
	if (*p == 2147483647 || *p < 0)
		return (ERROR);
	op->p = *p;
	*p = 0;
	return (TRUE);
}

int	decode_precision(char *f, size_t c, int n, t_o *op)
{
	int		p;

	if (c == (size_t)n)
		return (c);
	p = 0;
	while (c < (size_t)n)
	{
		if (f[c] == '.')
		{
			c = cal_precision(f, c + 1, &p);
			if (apply_precision(&p, op) < 0)
				return (ERROR);
			continue ;
		}
		c++;
	}
	return (TRUE);
}
