/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:
 */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:28:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/21 19:20:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal(void) : _type("undefined")
{
    std::cout << "WrongAnimal has been created via default constructor"
              << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src.getType())
{
    std::cout << "WrongAnimal has been created via copy constructor"
              << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
    this->_type = rhs.getType();
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound(void) const
{
    std::cout << "~MENACING GROWLING NOISES~" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongAnimal::getType(void) const { return (this->_type); }
