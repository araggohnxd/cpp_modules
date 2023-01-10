/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printUtils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:43:47 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/10 20:04:25 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

void handleWhitespaces(char &c)
{
    char const  characters[] = " \f\n\r\t\v";
    char const *strings[]    = {"' ' (whitespace)",
                                "'\\f' (form-feed)",
                                "'\\n' (newline)",
                                "'\\r' (carriage return)",
                                "'\\t' (horizontal tab)",
                                "'\\v' (vertical tab)",
                                NULL};

    for (size_t i = 0; i < 7; ++i) {
        if (c == characters[i]) {
            std::cout << "char:   " << strings[i] << '\n';
            return;
        }
    }
}

void printError(std::string &str)
{
    std::cerr << "The input '" << str
              << "' not a char, or a integer, nor a float, "
                 "neither a double."
              << std::endl;
}

void printSingleChar(std::string::iterator const &it)
{
    if (std::isspace(*it))
        handleWhitespaces(*it);
    else if (!std::isprint(*it))
        std::cout << "char:   non-displayable character\n";
    else
        std::cout << "char:   '" << *it << "'\n";
    std::cout.precision(1);
    std::cout << "int:    " << std::fixed << static_cast<int>(*it) << '\n'
              << "float:  " << std::fixed << static_cast<float>(*it) << "f\n"
              << "double: " << std::fixed << static_cast<double>(*it) << '\n'
              << std::endl;
}
