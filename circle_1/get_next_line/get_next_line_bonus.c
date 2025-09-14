/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:53:14 by minhulee          #+#    #+#             */
/*   Updated: 2023/11/24 12:44:03 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	double_backup(char **backup, int len)
{
	char	*tmp;

	tmp = *backup;
	if (512 < BUFFER_SIZE)
		len += BUFFER_SIZE;
	else
		len += 512;
	*backup = (char *)malloc((len + 1) * sizeof(char));
	if (!*backup)
	{
		*backup = tmp;
		return (-1);
	}
	(*backup)[0] = '\0';
	gnl_strcat(*backup, tmp);
	free(tmp);
	return (len);
}

int	get_next_buff(int fd, char **backup)
{
	int	read_size;
	int	total;
	int	len;

	total = gnl_strlen(*backup);
	len = gnl_strlen(*backup);
	while (gnl_strchr(*backup, '\n') < 0)
	{
		if (total + BUFFER_SIZE > len)
		{
			len = double_backup(backup, len);
			if (len < 0)
				return (-1);
		}
		read_size = read(fd, *backup + total, BUFFER_SIZE);
		total += read_size;
		if (read_size < 0)
			return (-1);
		(*backup)[total] = '\0';
		if (read_size == 0)
			return (0);
	}
	(*backup)[total] = '\0';
	return (1);
}

char	*get_reach_eof(t_fd **cur, t_fd **head)
{
	char	*result;

	result = gnl_strcut((*cur)->backup, 0, gnl_strlen((*cur)->backup));
	if ((*cur)->backup)
	{
		free((*cur)->backup);
		(*cur)->backup = 0;
	}
	if (*cur == *head)
		*head = (*cur)->next;
	if ((*cur)->pre)
		((*cur)->pre)->next = (*cur)->next;
	if ((*cur)->next)
		((*cur)->next)->pre = (*cur)->pre;
	free(*cur);
	return (result);
}

char	*get_reach_newline(t_fd **cur, t_fd **head, int std)
{
	char	*result;
	char	*tmp;

	result = gnl_strcut((*cur)->backup, 0, std + 1);
	tmp = gnl_strcut((*cur)->backup, std + 1, gnl_strlen((*cur)->backup));
	if (!result || !tmp)
	{
		if (result)
			free(result);
		if (tmp)
			free(tmp);
		free((*cur)->backup);
		if (*cur == *head)
			*head = (*cur)->next;
		if ((*cur)->pre)
			((*cur)->pre)->next = (*cur)->next;
		if ((*cur)->next)
			((*cur)->next)->pre = (*cur)->pre;
		free(*cur);
		return (0);
	}
	free((*cur)->backup);
	(*cur)->backup = tmp;
	return (result);
}

char	*get_next_line(int fd)
{
	static t_fd	*fd_lst_h;
	t_fd		*cur;
	int			result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	cur = get_fd_backup(fd, &fd_lst_h);
	if (!cur)
		return (0);
	result = get_next_buff(fd, &(cur->backup));
	if (result < 0)
	{
		free(cur->backup);
		if (cur == fd_lst_h)
			fd_lst_h = cur->next;
		if (cur->pre)
			(cur->pre)->next = cur->next;
		if (cur->next)
			(cur->next)->pre = cur->pre;
		free(cur);
		return (0);
	}
	if (result == 0)
		return (get_reach_eof(&cur, &fd_lst_h));
	return (get_reach_newline(&cur, &fd_lst_h, gnl_strchr(cur->backup, '\n')));
}
