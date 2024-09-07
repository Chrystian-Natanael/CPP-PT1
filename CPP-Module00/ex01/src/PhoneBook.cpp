/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:18:53 by cnatanae          #+#    #+#             */
/*   Updated: 2024/09/07 13:02:10 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook(void) {
	std::cout << "PhoneBook Constructor Called" << std::endl;
	currIndex = 0;
	numOfContacts = 0;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook Destructor Called" << std::endl;
}

bool	validName(const std::string &name) {
	std::string::const_iterator it;
	if (name.empty() || name.size() < 2)
		return (false);
	for (it = name.begin() ; it != name.end() ; it++) {
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
	if (*(phone.begin()) == '+') {
		limit_phone += 3;
		phone.erase(0, 1);
	}
	for (it = phone.begin() ; it != phone.end() ; it++) {
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
	if (numOfContacts < 8)
		numOfContacts++;
}

void PhoneBook::searchContact() {
	int	userInput = -1;

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
	do {
		std::cout << "Insert the index of contact: ";
		std::cin >> userInput;
		if (std::cin.fail() || userInput <= 0 || userInput > numOfContacts)
			std::cerr << std::endl << BRED << "Invalid Index, try again: " << RST << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (userInput <= 0 || userInput > numOfContacts);
	userInput--;
	std::cout << std::endl << "First Name: " << listContacts[userInput].getFirstName() << std::endl;
	std::cout << "Last Name: " << listContacts[userInput].getLastName() << std::endl;
	std::cout << "Nickname: " << listContacts[userInput].getNickname() << std::endl;
	std::cout << "Phone Number: " << listContacts[userInput].getPhoneNumber() << std::endl;
	std::cout << "The Darkest Secret: " << listContacts[userInput].getDarkestSecret() << std::endl << std::endl;
}