/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:59:12 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/16 13:06:43 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string  htib      = "HI THIS IS BRAIN";
    std::string *stringPTR = &htib;
    std::string &stringREF = htib;

    std::cout << "String 'htib' memory address: " << &htib << std::endl;
    std::cout << "Memory address held by PTR:   " << stringPTR << std::endl;
    std::cout << "Memory address held by REF:   " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "String 'htib' value:          " << htib << std::endl;
    std::cout << "Value pointed to by PTR:      " << *stringPTR << std::endl;
    std::cout << "Value pointed to by REF:      " << stringREF << std::endl;
    return (0);
}
