/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:47:16 by cnatanae          #+#    #+#             */
/*   Updated: 2024/08/29 19:21:19 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstdio>
#include "../includes/PhoneBook.hpp"

bool	g_finish = false;

void	welcome(void) {
	std::string	line = "=======================================";
	std::string	message = "👋 Welcome to Forty Two Books";
	int			padding = (line.length() - message.length()) / 2;
	std::string	spaces(padding, ' ');
	
	std::cout << BLNK << B << line << RST << std::endl;
	std::cout << BBLU << spaces << message << spaces << std::endl;
	std::cout << BLNK << B << line << RST << std::endl;
}

std::string promt(void) {
	std::string option;

	option.clear();
	std::cout << "Choose a option below: " << std::endl;
	std::cout << UNDL << G << BOLD << "ADD" << RST << std::setw(7) << std::setfill(' ') << "-" << " To add a new contact in your book" << std::endl;
	std::cout << UNDL << RED << BOLD << "EXIT" << RST << std::setw(6) << std::setfill(' ') << "-" << " To close program" << std::endl;
	std::cout << UNDL << Y << BOLD << "SEARCH" << RST << std::setw(4) << std::setfill(' ') << "-" << " To search a specified contact" << std::endl << std::endl;

	while (1) {
		std::getline(std::cin, option);
		if (!option.empty())
			break ;
	}
	return (option);
}

void	handleInput(std::string input, PhoneBook &ftBook) {
	if (!input.compare("ADD"))
		ftBook.addContact();
	else if (!input.compare("EXIT")) {
		g_finish = true;
		std::cout << C << UNDL << "You lost your favorite contacts..." << RST << std::endl;
	}
	else if (!input.compare("SEARCH"))
		ftBook.searchContact();
	else
		std::cerr << BRED << "Invalid option!"<< RST << std::endl;
}

int	main(void) {
	PhoneBook	ftBook;
	std::string	input;

	welcome();
	while (!g_finish)
	{
		input = promt();
		handleInput(input, ftBook);
	}
	return (0);
}
