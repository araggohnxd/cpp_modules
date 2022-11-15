/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:56:40 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/15 16:45:58 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ex01.hpp>

int main(void)
{
    PhoneBook   phonebook;
    std::string input;
    std::string str;

    std::cout << "Welcome to your phonebook! Here, you can:" << std::endl;
    std::cout << "ADD contacts, SEARCH for a contact, or EXIT." << std::endl;
    std::cout << "Pick an option!\n" << std::endl;
    while (true) {
        std::getline(std::cin, input);
        if (std::cin.eof() || input == "EXIT")
            break;
        else if (input == "ADD")
            phonebook.prompt_add();
        else if (input == "SEARCH")
            phonebook.prompt_search();
        else
            std::cerr << input << " is not a valid option." << std::endl;
    }
    return (0);
}
