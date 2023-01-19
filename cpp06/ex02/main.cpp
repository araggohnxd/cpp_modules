/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:03:33 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/19 20:07:09 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base *generate(void)
{
    int const type = std::rand() % 3;

    switch (type) {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
    }
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "This pointer derives from class A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "This pointer derives from class B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "This pointer derives from class C" << std::endl;
    else
        std::cerr << "No match for this pointer" << std::endl;
}

void identify(Base &p)
{
    try {
        A a = dynamic_cast<A &>(p);
        std::cout << "This reference derives from class A" << std::endl;
    } catch (std::exception const &ea) {
        try {
            B b = dynamic_cast<B &>(p);
            std::cout << "This reference derives from class B" << std::endl;
        } catch (std::exception const &eb) {
            try {
                C c = dynamic_cast<C &>(p);
                std::cout << "This reference derives from class C" << std::endl;
            } catch (std::exception const &ec) {
                std::cerr << "No match for this reference" << std::endl;
            }
        }
    }
}

int main(void)
{
    std::srand(time(NULL));

    Base *ptr = generate();
    Base &ref = *ptr;
    identify(ptr);
    identify(ref);
    delete ptr;

    Base *nul = NULL;
    // Base &nil = *nul;
    identify(nul);
    // identify(nil);

    return (0);
}
