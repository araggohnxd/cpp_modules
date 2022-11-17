/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:58:07 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/17 14:58:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    {
        Fixed       a;
        Fixed const b(Fixed(5.05f) * Fixed(2));

        std::cout << "============== Subject tests ==============" << std::endl;
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max(a, b) << std::endl;
        std::cout << std::endl;
    }
    Fixed a(42), b(123), c(21.12f), d, e(a), f(-42), g(-12.21f);

    std::cout << "============= Comparison tests ============\n"
              << "a: " << a << " -- b: " << b << " -- c: " << c
              << " -- d: " << d << " -- e: " << e << " -- f: " << f
              << " -- g: " << g << "\n"
              << "'a' == 'b' : " << (a == b ? "true" : "false") << "\n"
              << "'a' == 'e' : " << (a == e ? "true" : "false") << "\n"
              << "'a' != 'e' : " << (a != e ? "true" : "false") << "\n"
              << "'a' != 'd' : " << (a != d ? "true" : "false") << "\n"
              << "'a'  > 'c' : " << (a > c ? "true" : "false") << "\n"
              << "'a'  > 'b' : " << (a > b ? "true" : "false") << "\n"
              << "'a'  > 'e' : " << (a > e ? "true" : "false") << "\n"
              << "'a'  < 'c' : " << (a < c ? "true" : "false") << "\n"
              << "'a'  < 'b' : " << (a < b ? "true" : "false") << "\n"
              << "'a'  < 'e' : " << (a < e ? "true" : "false") << "\n"
              << "'a' >= 'c' : " << (a >= c ? "true" : "false") << "\n"
              << "'a' >= 'b' : " << (a >= b ? "true" : "false") << "\n"
              << "'a' >= 'e' : " << (a >= e ? "true" : "false") << "\n"
              << "'a' <= 'c' : " << (a <= c ? "true" : "false") << "\n"
              << "'a' <= 'b' : " << (a <= b ? "true" : "false") << "\n"
              << "'a' <= 'e' : " << (a <= e ? "true" : "false") << "\n"
              << std::endl;

    std::cout << "============= Arithmetic tests ============\n"
              << "a: " << a << " -- b: " << b << " -- c: " << c
              << " -- d: " << d << " -- e: " << e << " -- f: " << f
              << " -- g: " << g << "\n"
              << "'a' + 'b' : " << (a + b) << "\n"
              << "'a' + 'd' : " << (a + d) << "\n"
              << "'a' + 'f' : " << (a + f) << "\n"
              << "'a' + 'g' : " << (a + g) << "\n"
              << "'a' - 'b' : " << (a - b) << "\n"
              << "'a' - 'd' : " << (a - d) << "\n"
              << "'a' - 'f' : " << (a - f) << "\n"
              << "'a' - 'g' : " << (a - g) << "\n"
              << "'a' * 'b' : " << (a * b) << "\n"
              << "'a' * 'd' : " << (a * d) << "\n"
              << "'a' * 'f' : " << (a * f) << "\n"
              << "'a' * 'g' : " << (a * g) << "\n"
              << "'a' / 'b' : " << (a / b) << "\n"
              << "'a' / 'c' : " << (a / c) << "\n"
              << "'a' / 'f' : " << (a / f) << "\n"
              << "'a' / 'g' : " << (a / g) << "\n"
              << std::endl;

    std::cout << "============= Increment tests =============\n"
              << "a: " << a << " -- b: " << b << " -- c: " << c
              << " -- d: " << d << " -- e: " << e << " -- f: " << f
              << " -- g: " << g << std::endl;
    a = ++d;
    std::cout << "'a' = '++d' : a: " << a << " -- d: " << d << std::endl;
    a = d++;
    std::cout << "'a' = 'd++' : a: " << a << " -- d: " << d << std::endl;
    a = --d;
    std::cout << "'a' = '--d' : a: " << a << " -- d: " << d << std::endl;
    a = d--;
    std::cout << "'a' = 'd--' : a: " << a << " -- d: " << d << std::endl;
    a = 42;
    std::cout << std::endl;

    std::cout << "=========== Extra methods tests ===========\n"
              << "a: " << a << " -- b: " << b << " -- c: " << c
              << " -- d: " << d << " -- e: " << e << " -- f: " << f
              << " -- g: " << g << "\n"
              << "min 'a, b' : " << Fixed::min(a, b) << "\n"
              << "min 'a, c' : " << Fixed::min(a, c) << "\n"
              << "min 'a, d' : " << Fixed::min(a, d) << "\n"
              << "max 'a, b' : " << Fixed::max(a, b) << "\n"
              << "max 'a, c' : " << Fixed::max(a, c) << "\n"
              << "max 'a, d' : " << Fixed::max(a, d) << "\n"
              << std::endl;
    return (0);
}
