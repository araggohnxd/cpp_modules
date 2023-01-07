/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:17:02 by maolivei          #+#    #+#             */
/*   Updated: 2022/12/20 15:28:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  zombieBob("Bob");
    Zombie *zombieEdd = newZombie("Edd");

    zombieBob.announce();
    zombieEdd->announce();
    randomChump("Zac");
    delete zombieEdd;
    return (0);
}
