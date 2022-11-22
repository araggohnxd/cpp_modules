/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:04:01 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Ice Materia has been created via default constructor"
              << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
    std::cout << "Ice Materia has been created via copy constructor"
              << std::endl;
}

Ice::Ice(std::string const &type) : AMateria(type)
{
    std::cout << "Ice Materia has been created via string constructor"
              << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice(void) { std::cout << "Ice Materia has been destroyed" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &Ice::operator=(Ice const &rhs)
{
    this->_type = rhs._type;
    std::cout << "Ice Materia assignment operator has been called" << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Ice *Ice::clone(void) const
{
    std::cout << "Ice Materia clone function has been called" << std::endl;
    return (new Ice());
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}
