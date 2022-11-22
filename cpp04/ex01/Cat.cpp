/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:20 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 13:51:25 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(void) : Animal()
{
    this->_type  = "Cat";
    this->_brain = new Brain;
    std::cout << "Cat has been created via default constructor" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    this->_type  = src._type;
    this->_brain = new Brain(*src._brain);
    std::cout << "Cat has been created via copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat(void)
{
    delete this->_brain;
    std::cout << "Cat has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=(Cat const &rhs)
{
    this->_type   = rhs._type;
    *this->_brain = *rhs._brain;
    std::cout << "Cat assignment overload called" << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound(void) const
{
    std::cout << "~~meow mow mrow mrrr mew~~" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain *Cat::getBrain(void) const { return (this->_brain); }
