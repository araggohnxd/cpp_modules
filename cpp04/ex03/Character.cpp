/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:29:41 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(void) : _name("undefined")
{
    std::memset(this->_inventory, 0, (sizeof(AMateria *) * MAX_SLOTS));
    std::cout << "Character " << this->_name
              << " has been created via default constructor" << std::endl;
}

Character::Character(Character const &src) : _name(src._name)
{
    std::memset(this->_inventory, 0, (sizeof(AMateria *) * MAX_SLOTS));
    for (size_t i = 0; i < MAX_SLOTS; ++i)
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
    std::cout << "Character " << this->_name
              << " has been created via copy constructor" << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
    std::memset(this->_inventory, 0, (sizeof(AMateria *) * MAX_SLOTS));
    std::cout << "Character " << this->_name
              << " has been created via string constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character(void)
{
    for (size_t i = 0; i < MAX_SLOTS; ++i)
        delete this->_inventory[i];
    std::cout << "Character " << this->_name << " has been destroyed"
              << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &Character::operator=(Character const &rhs)
{
    this->_name = rhs._name;
    for (size_t i = 0; i < MAX_SLOTS; ++i)
        delete this->_inventory[i];
    std::memset(this->_inventory, 0, (sizeof(AMateria *) * MAX_SLOTS));
    for (size_t i = 0; i < MAX_SLOTS; ++i)
        if (rhs._inventory[i])
            this->_inventory[i] = rhs._inventory[i]->clone();
    std::cout << "Character assignment operator has been called" << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria *m)
{
    size_t index;

    for (index = 0; index < MAX_SLOTS; ++index)
        if (!this->_inventory[index])
            break;
    if (index == MAX_SLOTS) {
        std::cout << "Cannot equip, " << this->_name << "'s inventory is full!"
                  << std::endl;
        return;
    }
    this->_inventory[index] = m;
    std::cout << this->_name << " equipped new Materia in slot " << index << "!"
              << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= MAX_SLOTS) {
        std::cout << "Cannot unequip, " << idx
                  << " is not a valid inventory slot!" << std::endl;
        return;
    }
    if (!this->_inventory[idx]) {
        std::cout << "Cannot unequip, " << this->_name << "'s inventory slot "
                  << idx << " is empty!" << std::endl;
        return;
    }
    this->_inventory[idx] = NULL;
    std::cout << this->_name << " unequipped Materia in slot " << idx << "!"
              << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= MAX_SLOTS) {
        std::cout << "Cannot use, " << idx << " is not a valid inventory slot!"
                  << std::endl;
        return;
    }
    if (!this->_inventory[idx]) {
        std::cout << "Cannot use, " << this->_name << "'s inventory slot "
                  << idx << " is empty!" << std::endl;
        return;
    }
    this->_inventory[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &Character::getName(void) const { return (this->_name); }
