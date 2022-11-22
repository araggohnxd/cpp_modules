/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:28:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 15:05:50 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal(void) : _type("undefined")
{
    std::cout << "AAnimal has been created via default constructor"
              << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) : _type(src._type)
{
    std::cout << "AAnimal has been created via copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
    this->_type = rhs._type;
    std::cout << "AAnimal assignment overload called" << std::endl;
    return (*this);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AAnimal::getType(void) const { return (this->_type); }
