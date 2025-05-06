/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:12:33 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/06 16:16:54 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip> //to manage input and output formatting
#include "Contact.hpp"

void Contact::setContact()
{
	std::cout << "First name: ";
	std::getline(std::cin, firstName);
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	std::cout << "NickName: ";
	std::getline(std::cin, nickName);
	std::cout << "Phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkestSecret);
}

void Contact::displayBrief(int i) const//sets the width parameter of the stream out or in to exactly n
{
	std::cout << std::setw(10) << index << "|";
	std::string fields[3] = {firstName, lastName, nickName};
	for(int i = 0; i < 3; i++)
	{
		std::string val = fields[i];
		if(val.length() > 10)
			val = val.substr(0, 9) + ".";
		std::cout << std::setw(10) << val << "|";
	}
	std::cout <<std::endl;
}

void Contact::displayFull() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName<< std::endl;
	std::cout << "Nick name: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;	
}

bool Contact::isEmpty() const
{
	return firstName.empty();
}