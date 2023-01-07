/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:03:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/12/20 15:28:51 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp" /* Contact class */
#include <iomanip>     /* setw, right */
#include <iostream>    /* cin, cout, cerr */
#include <stdlib.h>    /* atoi */
#include <string>      /* string class */

#define MAX_CONTACTS 8
#define MAX_FIELDS   5
#define SEPARATOR    " +---------------------------------------------------+"
#define PIPE         " | "

class PhoneBook {
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void prompt_add(void);
        void prompt_search(void);

    private:
        void        _add(std::string firstname,
                         std::string lastname,
                         std::string nickname,
                         std::string secret,
                         std::string phone);
        void        _search(int index);
        void        _skip_whitespaces(std::string &name);
        int         _check_text_field(std::string str);
        int         _check_phone_number(std::string phone);
        int         _check_contact_index(std::string index);
        std::string _trunc(std::string str);

        Contact _contacts[MAX_CONTACTS];
        size_t  _total_contacts, _current_index;
};

#endif /* PHONEBOOK_HPP */
