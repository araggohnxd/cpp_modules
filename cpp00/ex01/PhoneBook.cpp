/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:05:14 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/16 14:33:35 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _total_contacts(0), _current_index(0) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::_add(std::string firstname,
                     std::string lastname,
                     std::string nickname,
                     std::string secret,
                     std::string phone)
{
    if (this->_total_contacts < MAX_CONTACTS)
        ++this->_total_contacts;
    else
        std::cout << "Contacts are full! Replacing oldest at index "
                  << (this->_current_index + 1) << "." << std::endl;
    this->_contacts[this->_current_index].set_firstname(firstname);
    this->_contacts[this->_current_index].set_lastname(lastname);
    this->_contacts[this->_current_index].set_nickname(nickname);
    this->_contacts[this->_current_index].set_secret(secret);
    this->_contacts[this->_current_index].set_phone(phone);
    this->_current_index = (this->_current_index + 1) % MAX_CONTACTS;
    std::cout << firstname << " was added to the phonebook!\n" << std::endl;
}

void PhoneBook::_search(int index)
{
    std::cout << "First name: " << this->_contacts[index].get_firstname()
              << std::endl;
    std::cout << "Last name: " << this->_contacts[index].get_lastname()
              << std::endl;
    std::cout << "Nickname: " << this->_contacts[index].get_nickname()
              << std::endl;
    std::cout << "Phone number: " << this->_contacts[index].get_phone()
              << std::endl;
    std::cout << "Darkest secret: " << this->_contacts[index].get_secret()
              << std::endl;
    std::cout << std::endl;
}

void PhoneBook::prompt_add(void)
{
    size_t      index = 0;
    std::string field[MAX_FIELDS];
    std::string prompt[MAX_FIELDS] = {"Insert new contact's first name: ",
                                      "Insert new contact's last name: ",
                                      "Insert new contact's nickname: ",
                                      "Insert new contact's darkest secret: ",
                                      "Insert new contact's phone number: "};

    while (index < MAX_FIELDS) {
        std::cout << prompt[index];
        std::getline(std::cin, field[index]);
        if (std::cin.eof())
            return;
        if (index == 4) {
            if (this->_check_phone_number(field[index]) == 0)
                ++index;
        } else if (this->_check_text_field(field[index]) == 0)
            ++index;
    }
    this->_add(field[0], field[1], field[2], field[3], field[4]);
}

void PhoneBook::prompt_search(void)
{
    std::string str_index;
    int         int_index;

    if (this->_total_contacts == 0) {
        std::cout << "There are no contacts to search for!\n" << std::endl;
        return;
    }
    std::cout << SEPARATOR << std::endl;
    std::cout << std::right << PIPE;
    std::cout << std::setw(10) << "INDEX" << PIPE;
    std::cout << std::setw(10) << "FIRST NAME" << PIPE;
    std::cout << std::setw(10) << "LAST NAME" << PIPE;
    std::cout << std::setw(10) << "NICKNAME" << PIPE << std::endl;
    std::cout << SEPARATOR << std::endl;
    for (size_t i = 0; i < this->_total_contacts; ++i) {
        std::cout << std::setw(13) << i + 1 << PIPE << std::setw(10)
                  << this->_trunc(this->_contacts[i].get_firstname()) << PIPE;
        std::cout << std::setw(10)
                  << this->_trunc(this->_contacts[i].get_lastname()) << PIPE;
        std::cout << std::setw(10)
                  << this->_trunc(this->_contacts[i].get_nickname()) << PIPE;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    while (true) {
        std::cout << "Insert index of contact to display: ";
        std::getline(std::cin, str_index);
        if (std::cin.eof())
            return;
        this->_skip_whitespaces(str_index);
        if (str_index.empty())
            continue;
        if (this->_check_contact_index(str_index) == 0) {
            int_index = atoi(str_index.c_str());
            if (int_index > 0 && int_index <= (int)this->_total_contacts)
                break;
            std::cout << str_index << " is not a valid index!" << std::endl;
        }
    }
    std::cout << std::endl;
    _search(int_index - 1);
}

void PhoneBook::_skip_whitespaces(std::string &name)
{
    for (std::string::iterator it = name.begin();
         it != name.end() && std::isspace(*it);
         ++it) {
        name.erase(it);
        it = name.begin() - 1;
    }
}

int PhoneBook::_check_contact_index(std::string index)
{
    if (index.empty()) {
        std::cout << index << " is not a valid index!" << std::endl;
        return (-1);
    }
    for (std::string::iterator it = index.begin(); it < index.end(); ++it) {
        if (!std::isdigit(*it)) {
            std::cout << index << " is not a valid index!" << std::endl;
            return (-1);
        }
    }
    return (0);
}

int PhoneBook::_check_phone_number(std::string phone)
{
    this->_skip_whitespaces(phone);
    if (phone.empty()) {
        std::cerr << "Field must not be empty!" << std::endl;
        return (-1);
    }
    for (std::string::iterator it = phone.begin(); it < phone.end(); ++it) {
        if (!std::isdigit(*it)) {
            std::cerr << "Phone number must contain only digits!" << std::endl;
            return (-1);
        }
    }
    if (phone.length() < MAX_CONTACTS || phone.length() > 9) {
        std::cerr << "Invalid phone number length!" << std::endl;
        return (-1);
    }
    return (0);
}

int PhoneBook::_check_text_field(std::string str)
{
    this->_skip_whitespaces(str);
    if (!str.empty())
        return (0);
    std::cerr << "Field must not be empty!" << std::endl;
    return (-1);
}

std::string PhoneBook::_trunc(std::string str)
{
    if (str.length() > 9)
        return (str.substr(0, 9) + ".");
    return (str);
}
