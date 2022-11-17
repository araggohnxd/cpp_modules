/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:58:07 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/17 18:29:05 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point const a(.5f, 1), b(.25f, .25f), c(.75f, .25f);

    std::cout << "=== Inside the triangle ===" << std::endl;
    std::cout << (bsp(a, b, c, Point(.5f, .5f)) ? "in" : "out") << std::endl;
    std::cout << (bsp(a, b, c, Point(.5f, .75f)) ? "in" : "out") << std::endl;
    std::cout << (bsp(a, b, c, Point(.37f, .6f)) ? "in" : "out") << std::endl;

    std::cout << "\n=== Outside the triangle ===" << std::endl;
    std::cout << (bsp(a, b, c, Point(.5f, 1)) ? "in" : "out") << std::endl;
    std::cout << (bsp(a, b, c, Point(.25f, .25f)) ? "in" : "out") << std::endl;
    std::cout << (bsp(a, b, c, Point(.75f, .25f)) ? "in" : "out") << std::endl;
    std::cout << (bsp(a, b, c, Point(.366f, .6f)) ? "in" : "out") << std::endl;
    std::cout << (bsp(a, b, c, Point(.75f, .5f)) ? "in" : "out") << std::endl;
    std::cout << (bsp(a, b, c, Point(.5f, 1.01f)) ? "in" : "out") << std::endl;
    std::cout << (bsp(a, b, c, Point(.36f, .6f)) ? "in" : "out") << std::endl;
    std::cout << (bsp(a, b, c, Point(.365f, .6f)) ? "in" : "out") << std::endl;
    return (0);
}
