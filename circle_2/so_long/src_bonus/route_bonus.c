/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 07:47:17 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/06 11:54:50 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	brute_force(t_m *m, t_md **md, int h, int w)
{
	if (h == 1 || h == m->h - 1)
		return ;
	if (w == 1 || w == m->w - 1)
		return ;
	if (md[h][w].t == W)
		return ;
	if (md[h][w].visited == TRUE)
		return ;
	md[h][w].visited = TRUE;
	brute_force(m, md, h + 1, w);
	brute_force(m, md, h - 1, w);
	brute_force(m, md, h, w - 1);
	brute_force(m, md, h, w + 1);
}

t_b	check_route(t_m *m, t_md **md)
{
	int	h;
	int	w;

	brute_force(m, md, m->start.y, m->start.x);
	h = 1;
	while (h < m->h - 1)
	{
		w = 1;
		while (w < m->w - 1)
		{
			if (md[h][w].t == C && md[h][w].visited == FALSE)
				return (FAIL);
			if (md[h][w].t == E && md[h][w].visited == FALSE)
				return (FAIL);
			md[h][w].visited = FALSE;
			w++;
		}
		h++;
	}
	return (TRUE);
}
