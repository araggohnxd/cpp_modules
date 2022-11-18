/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:24:04 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/17 21:45:35 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap bob("Bob"), edd("Edd"), zac("Zac"), jim("Jim"), fBob(bob), fEdd;

    fEdd = edd;
    bob.attack("Edd"); // 9
    edd.takeDamage(0);
    zac.beRepaired(32);
    jim.takeDamage(1337);
    jim.attack("Bob");
    bob.attack("Edd"); // 8
    bob.attack("Edd"); // 7
    bob.attack("Edd"); // 6
    bob.attack("Edd"); // 5
    bob.attack("Edd"); // 4
    bob.attack("Edd"); // 3
    bob.attack("Edd"); // 2
    bob.attack("Edd"); // 1
    bob.attack("Edd"); // 0
    bob.attack("Edd"); // fail
    return (0);
}
