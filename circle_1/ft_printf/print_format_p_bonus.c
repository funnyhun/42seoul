/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_p_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:39:25 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 16:42:28 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_reverse_p(size_t *count, unsigned long n, int p_len, t_o op)
{
	if (op.f[REVERSE] == FALSE)
	{
		if (print_width(count, p_len, &op) < 0)
			return (ERROR);
		if (print_sharp(count, op) < 0)
			return (ERROR);
		if (print_precision(count, base_len(n, HEXA, op), &op) < 0)
			return (ERROR);
		if (print_nbr_base(count, n, HEXA, op) < 0)
			return (ERROR);
	}
	else
	{
		if (print_sharp(count, op) < 0)
			return (ERROR);
		if (print_precision(count, base_len(n, HEXA, op), &op) < 0)
			return (ERROR);
		if (print_nbr_base(count, n, HEXA, op) < 0)
			return (ERROR);
		if (print_width(count, p_len, &op) < 0)
			return (ERROR);
	}
	return (TRUE);
}

int	print_format_p(void *p, t_o op)
{
	unsigned long	n;
	size_t			count;
	int				print_len;

	n = (unsigned long)p;
	count = 0;
	print_len = measure_len(base_len(n, HEXA, op), op) + 2;
	if (op.f[ZERO] && (op.p < 0 && op.w > 0) && !op.f[REVERSE])
	{
		op.p = op.w - 2;
		op.w = 0;
	}
	if (print_reverse_p(&count, n, print_len, op) < 0)
		return (ERROR);
	return (count);
}
