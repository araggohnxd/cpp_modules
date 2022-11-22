/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:04:01 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "Cure Materia has been created via default constructor"
              << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
    std::cout << "Cure Materia has been created via copy constructor"
              << std::endl;
}

Cure::Cure(std::string const &type) : AMateria(type)
{
    std::cout << "Cure Materia has been created via string constructor"
              << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure(void)
{
    std::cout << "Cure Materia has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &Cure::operator=(Cure const &rhs)
{
    this->_type = rhs._type;
    std::cout << "Cure Materia assignment operator has been called"
              << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Cure *Cure::clone(void) const
{
    std::cout << "Cure Materia clone function has been called" << std::endl;
    return (new Cure());
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
