/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:57:17 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/16 17:20:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(void) : ClapTrap()
{
    const_cast<std::string &>(this->_type) = "ScavTrap";
    this->_hitPoints                       = 100;
    this->_energyPoints                    = 50;
    this->_attackDamage                    = 20;
    std::cout << "ScavTrap " << this->_name
              << " has been created via default constructor!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
    const_cast<std::string &>(this->_type) = "ScavTrap";
    this->_hitPoints                       = src.getHP();
    this->_energyPoints                    = src.getEP();
    this->_attackDamage                    = src.getAD();
    std::cout << "ScavTrap " << this->_name
              << " has been created via copy constructor!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    const_cast<std::string &>(this->_type) = "ScavTrap";
    this->_hitPoints                       = 100;
    this->_energyPoints                    = 50;
    this->_attackDamage                    = 20;
    std::cout << "ScavTrap " << this->_name
              << " has been created via string constructor!" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->_name << " has been destroyed!"
              << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
    const_cast<std::string &>(this->_name) = rhs.getName();
    const_cast<std::string &>(this->_type) = "ScavTrap";
    this->_hitPoints                       = rhs.getHP();
    this->_energyPoints                    = rhs.getEP();
    this->_attackDamage                    = rhs.getAD();
    std::cout << "ScavTrap " << this->_name
              << " has called the assignment operator!" << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::guardGate(void)
{
    if (!tryAct())
        return;
    std::cout << this->_type << " " << this->_name
              << " is now in gatekeeper mode!" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
    if (!tryAct())
        return;
    std::cout << this->_type << " " << this->_name << " strikes " << target
              << ", dealing " << this->_attackDamage << " point"
              << (this->_attackDamage != 1 ? "s" : "") << " of damage!"
              << std::endl;
}
