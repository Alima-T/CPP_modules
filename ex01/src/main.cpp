/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <alima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:22:30 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/07 16:21:18 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook phonebook;
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command); //This reads the entire input line from the user into the command string.

		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")
			break;
	}
	return 0;
}
