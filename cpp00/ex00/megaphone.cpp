/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:39:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/13 20:39:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    std::string str;

    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (size_t i = 1; i < argc; ++i)
        str.append(argv[i]);
    for (std::string::iterator c = str.begin(); c != str.end(); ++c)
        *c = toupper(*c);
    std::cout << str << std::endl;
    return (0);
}
