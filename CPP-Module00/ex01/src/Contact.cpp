/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:06:23 by cnatanae          #+#    #+#             */
/*   Updated: 2024/08/24 17:11:11 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Contact Constructor Called" << std::endl;
}

Contact::~Contact(void) {
	std::cout << "Contact Destructor Called" << std::endl;
}

std::string Contact::getFirstName(void) {return this->_first_name;}

std::string Contact::getLastName(void) {return this->_last_name;}

std::string Contact::getNickname(void) {return this->_nickname;}

std::string Contact::getDarkestSecret(void) {return this->_darkest_secret;}
