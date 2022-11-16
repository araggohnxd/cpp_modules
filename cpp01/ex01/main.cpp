/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:17:02 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/16 12:56:26 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define DEFAULT_HORDE_SIZE 7

int main(void)
{
    Zombie  zombieBob("Bob");
    Zombie *horde = zombieHorde(DEFAULT_HORDE_SIZE, "Edd");

    std::cout << std::endl;
    zombieBob.announce();
    std::cout << std::endl;

    for (int i = 0; i < DEFAULT_HORDE_SIZE; ++i)
        horde[i].announce();
    std::cout << std::endl;

    delete[] horde;
    return (0);
}
