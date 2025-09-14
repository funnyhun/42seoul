/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:05:23 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 11:12:09 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

static void	is_dup(t_ps_info *info, char **split, int value)
{
	t_n	*cursor;

	cursor = info->a;
	while (cursor)
	{
		if (cursor->value == value)
		{
			free_split(split);
			exit_err(info, DUP_ARGV);
		}
		cursor = cursor->next;
	}
}

static void	is_digit_atoi(t_ps_info *info, char *s, int *res)
{
	long	sum;
	int		sign;

	sum = 0;
	sign = 1;
	if (*s == '-' && *(s + 1))
	{
		sign = -1;
		s++;
	}
	while (*s)
	{
		if (!('0' <= *s && *s <= '9'))
		{
			info->errno = NOT_DIGIT;
			return ;
		}
		sum *= 10;
		sum += *s - 48;
		s++;
	}
	if ((sign * sum) < INT_MIN || INT_MAX < (sign * sum))
		info->errno = NOT_INTEGER;
	*res = sum * sign;
}

void	parsing(t_ps_info *info, char **argv)
{
	int		res;
	char	**split;
	int		i;

	while (*argv)
	{
		split = ft_split(*argv, ' ');
		if (!split || !split[0])
			exit_err(info, OUT_OF_MEMORY);
		i = 0;
		while (split[i])
		{
			is_digit_atoi(info, split[i], &res);
			if (info->errno != OK)
			{
				free_split(split);
				exit_err(info, info->errno);
			}
			is_dup(info, split, res);
			new_node(info, res);
			i++;
		}
		free_split(split);
		argv++;
	}
}
