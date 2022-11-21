/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:20 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/21 19:20:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(void) : Animal()
{
    this->_type = "Cat";
    std::cout << "Cat has been created via default constructor" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    this->_type = src.getType();
    std::cout << "Cat has been created via copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat(void) { std::cout << "Cat has been destroyed" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=(Cat const &rhs)
{
    this->_type = rhs.getType();
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound(void) const
{
    std::cout << "~~meow mow mrow mrrr mew~~" << std::endl;
}
