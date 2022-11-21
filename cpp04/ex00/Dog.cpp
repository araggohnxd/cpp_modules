/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:20 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/21 19:20:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(void) : Animal()
{
    this->_type = "Dog";
    std::cout << "Dog has been created via default constructor" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
    this->_type = src.getType();
    std::cout << "Dog has been created via copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog(void) { std::cout << "Dog has been destroyed" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=(Dog const &rhs)
{
    this->_type = rhs.getType();
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound(void) const
{
    std::cout << "~~woof warrf hmmmgrr wof~~" << std::endl;
}
