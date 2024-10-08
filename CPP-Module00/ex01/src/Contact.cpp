/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:06:23 by cnatanae          #+#    #+#             */
/*   Updated: 2024/08/29 18:28:07 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Contact.hpp"

Contact::Contact(void) {
	std::cout << "Contact Constructor Called" << std::endl;
}

Contact::~Contact(void) {
	std::cout << "Contact Destructor Called" << std::endl;
}

std::string Contact::getFirstName(void) {
	return this->_first_name;
}

std::string Contact::getLastName(void) {
	return this->_last_name;
}

std::string Contact::getNickname(void) {
	return this->_nickname;
}

std::string Contact::getDarkestSecret(void) {
	return this->_darkest_secret;
}

std::string Contact::getPhoneNumber(void) {
	return this->_phone_number;
}

void Contact::setFirstName(std::string first_name) {
	this->_first_name = first_name;
}

void Contact::setLastName(std::string last_name) {
	this->_last_name = last_name;
}

void Contact::setNickname(std::string nickname) {
	this->_nickname= nickname;
}

void Contact::setPhoneNumber(std::string phone_number) {
	this->_phone_number = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret) {
	this->_darkest_secret = darkest_secret;
}