/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:38:16 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/30 14:13:22 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, size_t *count)
{
	if (write(1, &c, 1) < 0)
		return (ERROR);
	(*count)++;
	return (TRUE);
}

int	print_reverse_c(size_t *count, char c, t_o *op)
{
	if (op->f[REVERSE] == FALSE)
	{
		if (print_width(count, 1, op) < 0)
			return (ERROR);
		if (print_precision(count, 1, op) < 0)
			return (ERROR);
		if (print_char(c, count) < 0)
			return (ERROR);
	}
	else
	{
		if (print_precision(count, 1, op) < 0)
			return (ERROR);
		if (print_char(c, count) < 0)
			return (ERROR);
		if (print_width(count, 1, op) < 0)
			return (ERROR);
	}
	return (TRUE);
}

int	print_format_c(char c, t_o op)
{
	size_t	count;

	count = 0;
	op.p = -1;
	if ((op.f[ZERO]) && op.w > 0 && !op.f[REVERSE])
	{
		op.p = op.w;
		op.w = 0;
	}
	if (print_reverse_c(&count, c, &op) < 0)
		return (ERROR);
	return (count);
}
