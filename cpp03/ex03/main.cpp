/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:24:04 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/16 17:21:20 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap    zac("Zac"), max("Max"), leo("Leo");
    ScavTrap    bob("Bob"), edd("Edd"), jim("Jim");
    FragTrap    dan("Dan"), vin("Vin"), ted("Ted");
    DiamondTrap tim("Tim"), tyr("Tyr"), jon("Jon");

    std::cout << std::endl;
    {
        DiamondTrap axl(tim);
        axl.whoAmI();
    }
    std::cout << std::endl;
    {
        DiamondTrap pip;
        pip.whoAmI();
        pip = tim;
        pip.whoAmI();
    }
    std::cout << std::endl;
    zac.attack("Max");
    tim.attack("Edd");
    tyr.takeDamage(tim.getAD());
    tyr.guardGate();
    jon.highFivesGuys();
    tyr.beRepaired(42);
    jon.attack("Tim");
    tim.takeDamage(jon.getAD());
    jon.beRepaired(123);
    tyr.attack("Jon");
    jon.takeDamage(tyr.getAD());
    jon.beRepaired(32);
    tyr.takeDamage(1337);
    tyr.attack("Jon");
    tyr.highFivesGuys();
    tyr.takeDamage(1);
    tim.whoAmI();
    tyr.whoAmI();
    jon.whoAmI();
    std::cout << std::endl;
    return (0);
}
