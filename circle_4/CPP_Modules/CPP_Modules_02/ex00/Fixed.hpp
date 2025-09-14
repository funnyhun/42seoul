/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:40:02 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/22 06:31:53 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class   Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		~Fixed();

		Fixed	&operator=(const Fixed &other);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

	private:
		int					value;
		static const int	rawBits = 8;
};
