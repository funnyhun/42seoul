/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:45:50 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/30 14:13:14 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_num(char c)
{
	if (c >= 48 && c <= 57)
		return (TRUE);
	else
		return (FALSE);
}

int	apply_width(int *w, t_o *op)
{
	if (*w == 2147483647 || *w < 0)
		return (ERROR);
	if (*w != 0)
		op->w = *w;
	*w = 0;
	return (TRUE);
}

int	decode_width(char *f, size_t c, int n, t_o *op)
{
	int	w;

	w = 0;
	while (c < (size_t)n)
	{
		if (f[c] == '.')
		{
			c = pass_num(f, c + 1);
			continue ;
		}
		if (!is_num(f[c]))
		{
			if (apply_width(&w, op) < 0)
				return (ERROR);
			c++;
			continue ;
		}
		w = w * 10;
		w += f[c] - 48;
		c++;
	}
	return (TRUE);
}
