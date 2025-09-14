/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:15:10 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 12:24:21 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../../../lib/libft/libft.h"
# include "../../../lib/ft_printf/ft_printf.h"

# include "./push_swap_errno.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef enum e_bool
{
	FAIL = -1,
	FALSE,
	TRUE
}	t_b;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*pre;
	struct s_node	*next;
}	t_n;

typedef struct s_push_swap_info
{
	t_n		*a;
	t_n		*b;
	int		chunk;
	int		total;
	int		min;
	t_pseno	errno;
}	t_ps_info;

/* node */
void	new_node(t_ps_info *info, int index);
void	delete_list(t_ps_info *info);
t_n		*get_last_node(t_n *list);
void	push(t_n **src, t_n **dst);
void	swap(t_n *src);
void	rotation(t_n *src);
void	reverse_rotation(t_n *src);

/* checker */
void	exit_err(t_ps_info *info, int errno);
void	pa(t_ps_info *info);
void	pb(t_ps_info *info);
void	sa(t_ps_info *info);
void	sb(t_ps_info *info);
void	ss(t_ps_info *info);
void	ra(t_ps_info *info);
void	rb(t_ps_info *info);
void	rr(t_ps_info *info);
void	rra(t_ps_info *info);
void	rrb(t_ps_info *info);
void	rrr(t_ps_info *info);
void	parsing(t_ps_info *info, char **argv);
void	indexing(t_ps_info *info);

/* leaks */
void	check(void);

#endif