/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:57:17 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/18 16:05:04 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap(void) :
    ClapTrap("default_clap_name"),
    ScavTrap("default_clap_name"),
    FragTrap("default_clap_name"),
    _name("default")
{
    const_cast<std::string &>(this->_type) = "DiamondTrap";
    this->_hitPoints                       = FragTrap::_attackDamage;
    this->_energyPoints                    = ScavTrap::_energyPoints;
    this->_attackDamage                    = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name
              << " has been created via default constructor!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) :
    ClapTrap(src),
    ScavTrap(src),
    FragTrap(src),
    _name(src.getName())
{
    const_cast<std::string &>(this->_type) = "DiamondTrap";
    this->_hitPoints                       = src.getHP();
    this->_energyPoints                    = src.getEP();
    this->_attackDamage                    = src.getAD();
    std::cout << "DiamondTrap " << this->_name
              << " has been created via copy constructor!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
    ClapTrap(name + "_clap_name"),
    ScavTrap(name + "_clap_name"),
    FragTrap(name + "_clap_name"),
    _name(name)
{
    const_cast<std::string &>(this->_type) = "DiamondTrap";
    this->_hitPoints                       = FragTrap::_attackDamage;
    this->_energyPoints                    = ScavTrap::_energyPoints;
    this->_attackDamage                    = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name
              << " has been created via string constructor!" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->_name << " has been destroyed!"
              << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
    const_cast<std::string &>(this->_name) = rhs.getName();
    const_cast<std::string &>(this->_type) = "DiamondTrap";
    this->_hitPoints                       = rhs.getHP();
    this->_energyPoints                    = rhs.getEP();
    this->_attackDamage                    = rhs.getAD();
    std::cout << "DiamondTrap " << this->_name
              << " has called the assignment operator!" << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void DiamondTrap::whoAmI(void) const
{
    std::cout << "I am " << this->_type << " " << this->_name
              << ", and my ClapTrap name is " << ClapTrap::_name << "!"
              << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string DiamondTrap::getName(void) const { return (this->_name); }
