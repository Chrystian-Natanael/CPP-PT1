/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:18:53 by cnatanae          #+#    #+#             */
/*   Updated: 2024/08/26 17:38:20 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "PhoneBook Constructor Called" << std::endl;
	currIndex = 0;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destructor Called" << std::endl;
}

bool	validName(const std::string &name) {
	std::string::const_iterator it;
	if (name.empty() || name.size() < 2)
		return (false);
	for (it = name.cbegin() ; it != name.cend() ; it++) {
		if (!std::isalpha(*it) && *it != '-')
			return (false);
	}
	return (true);
}

bool	validAny(const std::string &name) {
	if (name.empty() || name.size() < 2)
		return (false);
	return (true);
}

bool	validPhone(std::string phone) {
	std::string::const_iterator	it;
	unsigned long				limit_phone = 11;

	if (phone.empty() || phone.size() < 2)
		return (false);
	if (*(phone.cbegin()) == '+') {
		limit_phone += 3;
		phone.erase(0, 1);
	}
	for (it = phone.cbegin() ; it != phone.cend() ; it++) {
		
		if (*it == ' ' || *it == '-' || *it == '(' || *it == ')')
			limit_phone++;
		else if (!std::isdigit(*it))
			return (false);
	}
	if (phone.size() > limit_phone)
		return (false);
	return (true);
}

std::string	validInput(std::string type, info validation) {
	std::string value;
	bool isValidValue = false;

	do {
		std::cout << "Type the " << type << ": ";
		std::getline(std::cin, value);
		switch (validation)
		{
			case NAME:
				isValidValue = validName(value);
				break;
			case PHONE:
				isValidValue = validPhone(value);
				break;
			case ANY:
				isValidValue = validAny(value);
				break;
			default:
				
				break;
		}
		if (isValidValue == false)
			std::cerr << BRED << "Invalid " << type << "!!" << RST << std::endl;
	} while (isValidValue == false);
	return (value);
}

void	PhoneBook::addContact(void) {
	Contact newContact;
	std::string firstName, lastName, nickname, phone, darkestSecret;

	if (currIndex >= 8)
		currIndex = 0;
	newContact.setFirstName(validInput("First Name", NAME));
	newContact.setLastName(validInput("Last Name", NAME));
	newContact.setNickname(validInput("Nickname", ANY));
	newContact.setPhoneNumber(validInput("Phone Number", PHONE));
	newContact.setDarkestSecret(validInput("Darkest Secret", ANY));
	listContacts[currIndex++] = newContact;
}

void PhoneBook::searchContact() {
	if (listContacts[0].getFirstName().empty()) {
		std::cout << BRED << "Your forty two book is empty..." << RST << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout	<< "|" << std::setw(10) << std::setfill(' ') << "Index"
				<< "|" << std::setw(10) << std::setfill(' ') << "First Name"
				<< "|" << std::setw(10) << std::setfill(' ') << "Last Name"
				<< "|" << std::setw(10) << std::setfill(' ') << "Nickname"
				<< "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0 ; i < 8 ; i++) {
		if (!listContacts[i].getFirstName().empty()) {
			std::cout << "|" << std::setw(10) << std::setfill(' ') << i + 1 << "|"
			<< std::setiosflags(std::ios::right) << std::setw(10)
			<< std::setiosflags(std::ios::right) << std::setfill(' ')
			<< (listContacts[i].getFirstName().size() > 10
				? listContacts[i].getFirstName().substr(0, 9) + "."
				: listContacts[i].getFirstName()) << "|"
			<< std::setiosflags(std::ios::right) << std::setw(10)
			<< std::setiosflags(std::ios::right) << std::setfill(' ')
			<< (listContacts[i].getLastName().size() > 10
				? listContacts[i].getLastName().substr(0, 9) + "."
				: listContacts[i].getLastName()) << "|"
			<< std::setiosflags(std::ios::right) << std::setw(10)
			<< std::setiosflags(std::ios::right) << std::setfill(' ')
			<< (listContacts[i].getNickname().size() > 10
				? listContacts[i].getNickname().substr(0, 9) + "."
				: listContacts[i].getNickname()) << "|" << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
		}
	}
}