/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:46:48 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/21 19:42:08 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    {
        std::cout << "\n========================="
                     " POLYMORPHISM USING POINTERS "
                     "========================="
                  << std::endl;
        const Animal *a = new Animal();
        const Animal *b = new Dog();
        const Animal *c = new Cat();
        std::cout << std::endl;

        std::cout << a->getType() << std::endl;
        std::cout << b->getType() << std::endl;
        std::cout << c->getType() << std::endl;
        std::cout << std::endl;

        a->makeSound();
        b->makeSound();
        c->makeSound();
        std::cout << std::endl;

        delete a;
        delete b;
        delete c;
        std::cout << std::endl;
    }
    {
        std::cout << "\n========================"
                     " POLYMORPHISM WITHOUT POINTERS "
                     "========================"
                  << std::endl;
        const Animal x = Animal();
        const Animal y = Dog();
        const Animal z = Cat();
        std::cout << std::endl;

        std::cout << x.getType() << std::endl;
        std::cout << y.getType() << std::endl;
        std::cout << z.getType() << std::endl;
        std::cout << std::endl;

        x.makeSound();
        y.makeSound();
        z.makeSound();
        std::cout << std::endl;
    }
    {
        std::cout << "\n======================"
                     " POLYMORPHISM WRONG USING POINTERS "
                     "======================"
                  << std::endl;
        const WrongAnimal *a = new WrongAnimal();
        const WrongAnimal *c = new WrongCat();
        std::cout << std::endl;

        std::cout << a->getType() << std::endl;
        std::cout << c->getType() << std::endl;
        std::cout << std::endl;

        a->makeSound();
        c->makeSound();
        std::cout << std::endl;

        delete a;
        delete c;
        std::cout << std::endl;
    }
    {
        std::cout << "\n====================="
                     " POLYMORPHISM WRONG WITHOUT POINTERS "
                     "====================="
                  << std::endl;
        const WrongAnimal x = WrongAnimal();
        const WrongAnimal z = WrongCat();
        std::cout << std::endl;

        std::cout << x.getType() << std::endl;
        std::cout << z.getType() << std::endl;
        std::cout << std::endl;

        x.makeSound();
        z.makeSound();
        std::cout << std::endl;
    }
    return (0);
}
