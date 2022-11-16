/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:07:23 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/16 19:18:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int checkUserInput(int argc)
{
    if (argc != 2) {
        if (argc > 2)
            std::cerr << "harl: Too many arguments" << std::endl;
        if (argc < 2)
            std::cerr << "harl: Too few arguments" << std::endl;
        std::cerr << "Usage: ./harl [DEBUG | INFO | WARNING | ERROR]"
                  << std::endl;
        return (-1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    Harl harl;

    if (checkUserInput(argc) != 0)
        return (1);
    harl.complain(argv[1]);
    return (0);
}
