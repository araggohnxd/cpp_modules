/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:54:21 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/17 21:45:32 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(void) :
    _name("default"),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap " << this->_name
              << " has been created via default constructor!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) :
    _name(src.getName()),
    _hitPoints(src.getHP()),
    _energyPoints(src.getEP()),
    _attackDamage(src.getAD())
{
    std::cout << "ClapTrap " << this->_name
              << " has been created via copy constructor!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
    _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap " << this->_name
              << " has been created via string constructor!" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << this->_name << " has been destroyed!"
              << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    this->_name         = rhs.getName();
    this->_hitPoints    = rhs.getHP();
    this->_energyPoints = rhs.getEP();
    this->_attackDamage = rhs.getAD();
    std::cout << "ClapTrap " << this->_name
              << " has called the assignment operator!" << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const std::string &target)
{
    if (!tryAct())
        return;
    std::cout << "ClapTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage << " point"
              << (this->_attackDamage != 1 ? "s" : "") << " of damage!"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > this->_hitPoints)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " took " << amount
              << " of damage, and now has " << this->_hitPoints << " hit point"
              << (this->_hitPoints != 1 ? "s" : "") << " remaining!"
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!tryAct())
        return;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " repaired itself, gaining "
              << amount << " hit points, and now has " << this->_hitPoints
              << " hit point" << (this->_hitPoints != 1 ? "s" : "")
              << " in total!" << std::endl;
}

bool ClapTrap::tryAct(void)
{
    if (this->_hitPoints <= 0)
        return (outOfHitPoints(), false);
    if (this->_energyPoints <= 0)
        return (outOfEnergy(), false);
    --this->_energyPoints;
    return (true);
}

void ClapTrap::outOfEnergy(void) const
{
    std::cout << "Cannot perform action, ClapTrap " << this->_name
              << " has no energy points left!" << std::endl;
}

void ClapTrap::outOfHitPoints(void) const
{
    std::cout << "Cannot perform action, ClapTrap " << this->_name
              << " has no hit points left!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ClapTrap::getName(void) const { return (this->_name); }

unsigned int ClapTrap::getHP(void) const { return (this->_hitPoints); }

unsigned int ClapTrap::getEP(void) const { return (this->_energyPoints); }

unsigned int ClapTrap::getAD(void) const { return (this->_attackDamage); }
