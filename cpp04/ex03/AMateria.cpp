/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:09:22 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:09 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria(void) : _type("undefined")
{
    std::cout << "AMateria has been created via default constructor"
              << std::endl;
}

AMateria::AMateria(AMateria const &src) : _type(src._type)
{
    std::cout << "AMateria has been created via copy constructor" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "AMateria has been created via string constructor"
              << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria(void)
{
    std::cout << "AMateria has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &AMateria::operator=(AMateria const &rhs)
{
    this->_type = rhs._type;
    std::cout << "AMateria assignment operator has been called" << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void AMateria::use(ICharacter &target)
{
    std::cout << "Cannot use '" << this->_type << "' Materia type on target "
              << target.getName() << "!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &AMateria::getType(void) const { return (this->_type); }
