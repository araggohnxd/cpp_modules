/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:20 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 13:51:34 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(void) : Animal()
{
    this->_type  = "Dog";
    this->_brain = new Brain;
    std::cout << "Dog has been created via default constructor" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
    this->_type  = src._type;
    this->_brain = new Brain(*src._brain);
    std::cout << "Dog has been created via copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog(void)
{
    delete this->_brain;
    std::cout << "Dog has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=(Dog const &rhs)
{
    this->_type   = rhs._type;
    *this->_brain = *rhs._brain;
    std::cout << "Dog assignment overload called" << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound(void) const
{
    std::cout << "~~woof warrf hmmmgrr wof~~" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain *Dog::getBrain(void) const { return (this->_brain); }
