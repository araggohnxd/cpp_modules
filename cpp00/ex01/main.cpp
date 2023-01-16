/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:56:40 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/16 14:30:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

int main(void)
{
    PhoneBook   phonebook;
    std::string input;
    std::string str;

    std::cout << "Welcome to your phonebook! Here, you can:\n"
              << "ADD contacts, SEARCH for a contact, or EXIT.\n"
              << "Pick an option!\n"
              << std::endl;
    while (true) {
        std::getline(std::cin, input);
        if (std::cin.eof() || input == "EXIT")
            break;
        else if (input.empty())
            continue;
        else if (input == "ADD")
            phonebook.prompt_add();
        else if (input == "SEARCH")
            phonebook.prompt_search();
        else
            std::cerr << input << " is not a valid option.\n" << std::endl;
    }
    return (0);
}
