/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:21:15 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/06 16:51:03 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook() : totalContacts(0), oldestIndex(0) {}

void PhoneBook::addContact() {
	contacts[oldestIndex].setContact();
	oldestIndex = (oldestIndex + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;
}

void PhoneBook::searchContacts() const {
	// std::cout << "Index|First Name| Last Name|  Nickname|" << std::endl;
	// for (int i = 0; i < totalContacts; i++) 
	// {
	// 	contacts[i].displayBrief(i);
	// }
	// std::cout << "Enter index to view: ";
	// int index;
	// if (!(std::cin >> index) || index < 0 || index >= totalContacts) 
	// {
	// 	std::cin.clear();
	// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// 	std::cout << "Invalid index." << std::endl;
	// 	return;
	// }
	// std::cin.ignore();
	// contacts[index].displayFull();
}
