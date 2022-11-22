/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:17:48 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource(void)
{
    std::memset(this->_materia, 0, (sizeof(AMateria *) * MAX_MATERIA));
    std::cout << "MateriaSource has been created via default constructor"
              << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    std::memset(this->_materia, 0, (sizeof(AMateria *) * MAX_MATERIA));
    for (size_t i = 0; i < MAX_MATERIA; ++i)
        if (src._materia[i])
            this->_materia[i] = src._materia[i]->clone();
    std::cout << "MateriaSource has been created via copy constructor"
              << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource(void)
{
    for (size_t i = 0; i < MAX_MATERIA; ++i)
        delete this->_materia[i];
    std::cout << "MateriaSource has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    for (size_t i = 0; i < MAX_MATERIA; ++i)
        delete this->_materia[i];
    std::memset(this->_materia, 0, (sizeof(AMateria *) * MAX_MATERIA));
    for (size_t i = 0; i < MAX_MATERIA; ++i)
        if (rhs._materia[i])
            this->_materia[i] = rhs._materia[i]->clone();
    std::cout << "MateriaSource assignment operator has been called"
              << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria *newMateria)
{
    size_t index;

    for (index = 0; index < MAX_MATERIA; ++index)
        if (!this->_materia[index])
            break;
    if (index == MAX_MATERIA) {
        std::cout << "Cannot learn, max MateriaSource capacity reached!"
                  << std::endl;
        return;
    }
    this->_materia[index] = newMateria;
    std::cout << "New materia " << newMateria->getType() << " learned!"
              << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    size_t index;

    for (index = 0; index < MAX_MATERIA; ++index)
        if (this->_materia[index])
            if (type == this->_materia[index]->getType())
                break;
    if (index == MAX_MATERIA) {
        std::cout << "Cannot create materia, " << type << " type is unknown!"
                  << std::endl;
        return (NULL);
    }
    std::cout << "Created new materia of type " << type << "!" << std::endl;
    return (this->_materia[index]->clone());
}
