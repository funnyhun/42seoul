/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:47:15 by minhulee          #+#    #+#             */
/*   Updated: 2023/11/24 12:44:11 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_strlen(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	gnl_strcat(char *s, char *s2)
{
	int	start;
	int	i;

	if (!s2)
		return ;
	start = gnl_strlen(s);
	i = 0;
	while (s2[i])
	{
		s[start] = s2[i];
		start++;
		i++;
	}
	s[start] = '\0';
}

int	gnl_strchr(char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = gnl_strlen(s);
	while (i < len)
	{
		if (s[i] == ((char)c))
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strcut(char *s, int start, int end)
{
	char	*r;
	int		i;

	if (gnl_strlen(s) == 0)
		return (0);
	if (start > end)
		return (0);
	r = (char *)malloc((end - start + 1) * sizeof(char));
	if (!r)
		return (0);
	i = 0;
	while (start < end)
	{
		r[i] = s[start];
		i++;
		start++;
	}
	r[i] = '\0';
	return (r);
}

t_fd	*get_fd_backup(int fd, t_fd **head)
{
	t_fd	*cursor;
	t_fd	*new;

	cursor = *head;
	while (cursor)
	{
		if (cursor->fd == fd)
			return (cursor);
		if (cursor->next)
			cursor = cursor->next;
		else
			break ;
	}
	new = (t_fd *)malloc(sizeof(t_fd));
	if (!new)
		return (0);
	new->fd = fd;
	new->pre = cursor;
	new->next = NULL;
	new->backup = NULL;
	if (!cursor)
		*head = new;
	else
		cursor->next = new;
	return (new);
}
