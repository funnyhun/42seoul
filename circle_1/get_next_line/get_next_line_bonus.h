/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 03:38:43 by minhulee          #+#    #+#             */
/*   Updated: 2023/11/24 12:44:32 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct fd_list
{
	int				fd;
	char			*backup;
	struct fd_list	*pre;
	struct fd_list	*next;
}	t_fd;

char	*get_next_line(int fd);
int		gnl_strlen(char *s);
int		gnl_strchr(char *s, int c);
char	*gnl_strcut(char *s, int start, int end);
void	gnl_strcat(char *s, char *s2);
t_fd	*get_fd_backup(int fd, t_fd **head);

#endif