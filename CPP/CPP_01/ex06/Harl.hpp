/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:22:44 by broy              #+#    #+#             */
/*   Updated: 2023/02/13 16:22:45 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);


public:
	Harl();
	~Harl();

	void	complain(std:: string level);

};

typedef void (Harl::*t_func) (void);
