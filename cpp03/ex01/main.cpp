/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:24:04 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/18 13:17:26 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap zac("Zac"), max("Max"), leo("Leo");
    ScavTrap bob("Bob"), edd("Edd"), jim("Jim");

    std::cout << std::endl;
    bob.attack("Edd");
    edd.takeDamage(bob.getAD());
    edd.beRepaired(42);
    edd.guardGate();
    bob.attack("Max");
    max.takeDamage(bob.getAD());
    max.beRepaired(123);
    leo.attack("Bob");
    bob.takeDamage(leo.getAD());
    leo.beRepaired(32);
    jim.takeDamage(1337);
    jim.attack("Bob");
    jim.guardGate();
    jim.takeDamage(1);
    std::cout << std::endl;
    return (0);
}
