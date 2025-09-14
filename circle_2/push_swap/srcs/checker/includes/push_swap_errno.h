/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errno.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:10:12 by minhulee          #+#    #+#             */
/*   Updated: 2024/05/27 12:43:52 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ERRNO_H
# define PUSH_SWAP_ERRNO_H

# define ERRNO_LEN 5

typedef enum e_push_swap_errno
{
	OK = -1,
	OUT_OF_MEMORY,
	NOT_DIGIT,
	NOT_INTEGER,
	DUP_ARGV,
	INVALID
}	t_pseno;

#endif