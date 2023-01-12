/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:55:59 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/12 13:52:32 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
    int const        numbers[]   = {2, 3, 5, 7, 11, 13, 17};
    size_t const     numbersSize = sizeof(numbers) / sizeof(numbers[0]);
    std::vector<int> vec;
    std::deque<int>  deq;
    std::list<int>   lst;

    std::cout << "=== BASE ARRAY ===\n";
    for (size_t i = 0; i < numbersSize; ++i) {
        std::cout << numbers[i] << ' ';
        vec.push_back(numbers[i]);
        deq.push_back(numbers[i]);
        lst.push_back(numbers[i]);
    }
    std::cout << "\n\n";
    {
        std::vector<int>::iterator match;

        std::cout << "=== SEARCH IN VECTOR ===\n";
        try {
            match = easyfind(vec, 13);
            std::cout << "13 was found in vector at index "
                      << std::distance(vec.begin(), match) << '\n';
        } catch (std::exception const &e) {
            std::cerr << "Could not find 13 in vector: " << e.what() << '\n';
        }
        try {
            match = easyfind(vec, 42);
            std::cout << "42 was found in vector at index "
                      << std::distance(vec.begin(), match) << '\n';
        } catch (std::exception const &e) {
            std::cerr << "Could not find 42 in vector: " << e.what() << '\n';
        }
    }
    std::cout << std::endl;
    {
        std::deque<int>::iterator match;

        std::cout << "=== SEARCH IN DEQUE ===\n";
        try {
            match = easyfind(deq, 5);
            std::cout << "5 was found in deque at index "
                      << std::distance(deq.begin(), match) << '\n';
        } catch (std::exception const &e) {
            std::cerr << "Could not find 5 in deque: " << e.what() << '\n';
        }
        try {
            match = easyfind(deq, 42);
            std::cout << "42 was found in deque at index "
                      << std::distance(deq.begin(), match) << '\n';
        } catch (std::exception const &e) {
            std::cerr << "Could not find 42 in deque: " << e.what() << '\n';
        }
    }
    std::cout << std::endl;
    {
        std::list<int>::iterator match;

        std::cout << "=== SEARCH IN LIST ===\n";
        try {
            match = easyfind(lst, 11);
            std::cout << "11 was found in list at index "
                      << std::distance(lst.begin(), match) << '\n';
        } catch (std::exception const &e) {
            std::cerr << "Could not find 11 in list: " << e.what() << '\n';
        }
        try {
            match = easyfind(lst, 42);
            std::cout << "42 was found in list at index "
                      << std::distance(lst.begin(), match) << '\n';
        } catch (std::exception const &e) {
            std::cerr << "Could not find 42 in list: " << e.what() << '\n';
        }
    }

    return (0);
}
