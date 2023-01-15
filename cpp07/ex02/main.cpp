/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:59:55 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/14 23:32:09 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <iostream>

#define MAX_VAL 750
int main(int, char **)
{
    Array<int> numbers(MAX_VAL);
    int       *mirror = new int[MAX_VAL];

    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        int const value = std::rand();
        numbers[i]      = value;
        mirror[i]       = value;
    }
    std::cout << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        Array<int> assign;

        assign = numbers;
        std::cout << "numbers size: " << numbers.size()
                  << "\ntmp size:     " << tmp.size()
                  << "\nassign size:  " << assign.size()
                  << "\ntest size:    " << test.size() << std::endl;
        assign = test;
    }
    std::cout << std::endl;

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    } catch (std::exception const &e) {
        std::cerr << "Couldn't access index -2: " << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch (std::exception const &e) {
        std::cerr << "Couldn't access index " << MAX_VAL << ": " << e.what()
                  << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = std::rand();
    }
    delete[] mirror;
    return (0);
}
