/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:00:44 by broy              #+#    #+#             */
/*   Updated: 2023/02/08 18:00:45 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
	int					index;
	static std::string	fields_name[5];
	std::string			informations[5];

	enum Field {
		FirstName = 0,
		LastName,
		Nickname,
		PhoneNumber,
		Secret
	};
public:
	Contact();
	virtual ~Contact();

	bool	set_informations(int index);
	void	display_header(void);
	void	display(void);
};

#endif
