/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:28:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 13:51:40 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(void) : _type("undefined")
{
    std::cout << "Animal has been created via default constructor" << std::endl;
}

Animal::Animal(const Animal &src) : _type(src._type)
{
    std::cout << "Animal has been created via copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal(void) { std::cout << "Animal has been destroyed" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &Animal::operator=(Animal const &rhs)
{
    this->_type = rhs._type;
    std::cout << "Animal assignment overload called" << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound(void) const
{
    std::cout << "~MENACING GROWLING NOISES~" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType(void) const { return (this->_type); }
