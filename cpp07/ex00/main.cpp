/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:16:25 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/11 18:31:44 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{
    int a = 2;
    int b = 3;
    std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "after swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "\nbefore swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "after swap: c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    float e = 42.01f;
    float f = 42.0f;
    std::cout << "\nbefore swap: e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << "after swap: e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
    std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;
    return (0);
}
