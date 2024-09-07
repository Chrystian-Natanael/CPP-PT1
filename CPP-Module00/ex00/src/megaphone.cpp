/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:08:11 by cnatanae          #+#    #+#             */
/*   Updated: 2024/09/07 12:01:37 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Standart library
#include <iostream>

// For use EXIT_SUCESS
#include <cstdlib>

// For use strcmp()/
#include <cstring>

std::string	processArgs(int argc, char **argv)
{
	if (argc > 1 && strcmp(argv[1], "")) {
		std::string result;
		for (int i = 1; i < argc; i++) {
			std::string str(argv[i]);
			for (size_t len = 0; len < str.size(); len++)
				str[len] = std::toupper(str[len]);
			result += str;
		}
		return result;
	} else
		return "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}

int	main(int argc, char **argv)
{
	std::cout << processArgs(argc, argv) << std::endl;
	return EXIT_SUCCESS;
}
