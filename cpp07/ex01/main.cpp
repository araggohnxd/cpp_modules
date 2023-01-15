/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:31:02 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/14 23:24:39 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T &x)
{
    std::cout << x << ' ';
}

int main(void)
{
    int    intArray[]     = {2, 3, 5, 7, 11};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
    iter(intArray, intArrayLength, print);
    std::cout << std::endl;

    std::string stringArray[] = {"foo", "bar", "baz"};
    size_t stringArrayLength  = sizeof(stringArray) / sizeof(stringArray[0]);
    iter(stringArray, stringArrayLength, print);
    std::cout << std::endl;

    return (0);
}
