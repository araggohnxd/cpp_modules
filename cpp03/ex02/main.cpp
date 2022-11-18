/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:24:04 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/18 13:25:10 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap zac("Zac"), max("Max"), leo("Leo");
    ScavTrap bob("Bob"), edd("Edd"), jim("Jim");
    FragTrap dan("Dan"), vin("Vin"), ted("Ted");

    std::cout << std::endl;
    bob.attack("Edd");
    edd.takeDamage(bob.getAD());
    edd.guardGate();
    vin.highFivesGuys();
    dan.beRepaired(42);
    dan.attack("Max");
    max.takeDamage(dan.getAD());
    max.beRepaired(123);
    leo.attack("Bob");
    bob.takeDamage(leo.getAD());
    leo.beRepaired(32);
    ted.takeDamage(1337);
    ted.attack("Bob");
    ted.highFivesGuys();
    ted.takeDamage(1);
    std::cout << std::endl;
    return (0);
}
