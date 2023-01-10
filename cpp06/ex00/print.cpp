/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:38:20 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/10 20:04:11 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

static void printCharacter(long double &ld)
{
    char c = static_cast<char>(ld);

    if (ld > CHAR_MAX || ld < CHAR_MIN)
        std::cout << "char:   impossible\n";
    else if (std::isspace(c))
        handleWhitespaces(c);
    else if (!std::isprint(c))
        std::cout << "char:   non-displayable character\n";
    else
        std::cout << "char:   '" << c << "'\n";
}

static void printInteger(long double &ld)
{
    int i = static_cast<int>(ld);

    if (ld > INT_MAX || ld < INT_MIN)
        std::cout << "int:    impossible\n";
    else
        std::cout << std::fixed << "int:    " << i << '\n';
}

static void printFloat(long double &ld)
{
    float f = static_cast<float>(ld);

    if (ld > FLT_MAX || ld < -FLT_MAX)
        std::cout << "float:  impossible\n";
    else
        std::cout << std::fixed << "float:  " << f << "f\n";
}

static void printDouble(long double &ld)
{
    double d = static_cast<double>(ld);

    if (ld > DBL_MAX || ld < -DBL_MAX)
        std::cout << "double: impossible\n";
    else
        std::cout << std::fixed << "double: " << d << '\n';
}

void printNumber(std::string &str)
{
    std::stringstream ss;
    long double       ld;

    ss.precision(1);
    ss << str;
    ss >> ld;
    std::cout.precision(1);
    printCharacter(ld);
    printInteger(ld);
    printFloat(ld);
    printDouble(ld);
    std::cout << std::endl;
}
