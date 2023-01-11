/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:15:56 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/10 22:41:52 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
    Data     *ptr, *deserialized;
    uintptr_t serialized;

    ptr          = new Data("foo bar");
    serialized   = serialize(ptr);
    deserialized = deserialize(serialized);
    std::cout << "Data before serialization:    " << ptr << ' ' << ptr->data
              << "\nData after serialization:     " << deserialized << ' '
              << deserialized->data << "\nSerialized: " << serialized
              << " == " << std::showbase << std::hex << serialized << std::endl;
    delete ptr;
    return (0);
}
