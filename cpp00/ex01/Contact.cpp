/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:00:43 by maolivei          #+#    #+#             */
/*   Updated: 2022/12/20 15:28:28 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

void Contact::set_firstname(const std::string str) { this->_firstname = str; }

void Contact::set_lastname(const std::string str) { this->_lastname = str; }

void Contact::set_nickname(const std::string str) { this->_nickname = str; }

void Contact::set_secret(const std::string str) { this->_secret = str; }

void Contact::set_phone(const std::string str) { this->_phone = str; }

std::string Contact::get_firstname(void) const { return (this->_firstname); }

std::string Contact::get_lastname(void) const { return (this->_lastname); }

std::string Contact::get_nickname(void) const { return (this->_nickname); }

std::string Contact::get_secret(void) const { return (this->_secret); }

std::string Contact::get_phone(void) const { return (this->_phone); }
