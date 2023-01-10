/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:39:07 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/10 20:02:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

static void printSpecialCaseFloat(std::string const &str)
{
    std::cout << "char:   impossible\n"
              << "int:    impossible\n"
              << "float:  " << str << '\n'
              << "double: " << str.substr(0, (str.size() - 1)) << '\n'
              << std::endl;
}

static void printSpecialCase(std::string const &str)
{
    std::cout << "char:   impossible\n"
              << "int:    impossible\n"
              << "float:  " << str << "f\n"
              << "double: " << str << '\n'
              << std::endl;
}

int specialCases(std::string const &str)
{
    if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
        return (printSpecialCase(str), 0);
    if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf")
        return (printSpecialCaseFloat(str), 0);
    return (1);
}
