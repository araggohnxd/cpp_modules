/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:57:17 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/18 13:26:33 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(void) : ClapTrap()
{
    const_cast<std::string &>(this->_type) = "FragTrap";
    this->_hitPoints                       = 100;
    this->_energyPoints                    = 100;
    this->_attackDamage                    = 30;
    std::cout << "FragTrap " << this->_name
              << " has been created via default constructor!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    const_cast<std::string &>(this->_type) = "FragTrap";
    this->_hitPoints                       = src.getHP();
    this->_energyPoints                    = src.getEP();
    this->_attackDamage                    = src.getAD();
    std::cout << "FragTrap " << this->_name
              << " has been created via copy constructor!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    const_cast<std::string &>(this->_type) = "FragTrap";
    this->_hitPoints                       = 100;
    this->_energyPoints                    = 100;
    this->_attackDamage                    = 30;
    std::cout << "FragTrap " << this->_name
              << " has been created via string constructor!" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->_name << " has been destroyed!"
              << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
    const_cast<std::string &>(this->_name) = rhs.getName();
    const_cast<std::string &>(this->_type) = "FragTrap";
    this->_hitPoints                       = rhs.getHP();
    this->_energyPoints                    = rhs.getEP();
    this->_attackDamage                    = rhs.getAD();
    std::cout << "FragTrap " << this->_name
              << " has called the assignment operator!" << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys(void)
{
    if (!tryAct())
        return;
    std::cout << this->_type << " " << this->_name
              << " requests a high five from everyone present!" << std::endl;
}
