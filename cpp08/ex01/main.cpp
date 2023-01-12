/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:26:29 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/12 17:57:46 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    Span             sp1(5);
    Span             sp2(5);
    std::vector<int> vec;

    sp1.addNumber(6);
    sp1.addNumber(3);
    sp1.addNumber(17);
    sp1.addNumber(9);
    sp1.addNumber(11);
    std::cout << "sp1 " << sp1 << '\n'
              << "Shortest span: " << sp1.shortestSpan() << '\n'
              << "Longest span: " << sp1.longestSpan() << '\n'
              << std::endl;

    vec.push_back(42);
    vec.push_back(777);
    vec.push_back(21);
    vec.push_back(1337);
    vec.push_back(19);
    sp2.addNumber(vec.begin(), vec.end());
    std::cout << "sp2 " << sp2 << '\n'
              << "Shortest span: " << sp2.shortestSpan() << '\n'
              << "Longest span: " << sp2.longestSpan() << '\n'
              << std::endl;

    try {
        sp1.addNumber(123);
    } catch (std::exception const &e) {
        std::cerr << "Couldn't add number: " << e.what() << '\n';
    }
    try {
        sp2.addNumber(vec.begin(), vec.end());
    } catch (std::exception const &e) {
        std::cerr << "Couldn't add range of numbers: " << e.what() << '\n';
    }
    return (0);
}
