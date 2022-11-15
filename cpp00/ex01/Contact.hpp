/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:39:38 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/15 14:44:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
    public:
        Contact(void);
        ~Contact(void);

        void set_firstname(const std::string str);
        void set_lastname(const std::string str);
        void set_nickname(const std::string str);
        void set_secret(const std::string str);
        void set_phone(const std::string str);

        std::string get_firstname(void);
        std::string get_lastname(void);
        std::string get_nickname(void);
        std::string get_secret(void);
        std::string get_phone(void);

    private:
        std::string _firstname, _lastname, _nickname, _secret, _phone;
};

#endif /* CONTACT_HPP */
