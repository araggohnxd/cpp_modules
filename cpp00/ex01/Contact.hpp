/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:39:38 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/15 19:02:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string> /* string class */

class Contact {
    public:
        Contact(void);
        ~Contact(void);

        void set_firstname(const std::string str);
        void set_lastname(const std::string str);
        void set_nickname(const std::string str);
        void set_secret(const std::string str);
        void set_phone(const std::string str);

        std::string get_firstname(void) const;
        std::string get_lastname(void) const;
        std::string get_nickname(void) const;
        std::string get_secret(void) const;
        std::string get_phone(void) const;

    private:
        std::string _firstname, _lastname, _nickname, _secret, _phone;
};

#endif /* CONTACT_HPP */
