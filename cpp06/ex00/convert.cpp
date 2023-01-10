/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:28:05 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/10 20:02:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int convert(std::string &str)
{
    bool dot = false;

    if (specialCases(str) == 0)
        return (0);
    if (str.length() == 1 && !std::isdigit(*(str.begin())))
        return (printSingleChar(str.begin()), 0);
    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        if ((*it == '-' || *it == '+') && it == str.begin())
            continue;
        if (!std::isdigit(*it)) {
            if (*it == '.' && !dot)
                dot = true;
            else if (*it == 'f' && (it + 1) == str.end())
                break;
            else
                return (printError(str), 1);
        }
    }
    return (printNumber(str), 0);
}
