/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:09:42 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/10 20:02:36 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

static int checkUserInput(int argc)
{
    if (argc != 2) {
        if (argc > 2)
            std::cerr << "Too many arguments" << std::endl;
        else if (argc < 2)
            std::cerr << "Too few arguments" << std::endl;
        std::cerr << "Usage: ./convert <simple literal>" << std::endl;
        return (-1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (checkUserInput(argc) != 0)
        return (1);

    std::string userInput(argv[1]);
    return (convert(userInput));
}
