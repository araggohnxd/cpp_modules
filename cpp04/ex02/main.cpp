/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:46:48 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 15:06:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define MAX_ANIMALS 10

int main(void)
{
    std::srand(time(NULL));
    {
        std::cout << "================================="
                     " SUBJECT TESTS "
                     "================================"
                  << std::endl;
        AAnimal     *animals[MAX_ANIMALS];
        size_t const max_half = MAX_ANIMALS / 2;

        for (size_t i = 0; i < MAX_ANIMALS; ++i) {
            if (i < max_half)
                animals[i] = new Dog;
            else
                animals[i] = new Cat;
        }
        std::cout << std::endl;

        for (size_t i = 0; i < MAX_ANIMALS; ++i)
            animals[i]->makeSound();
        std::cout << std::endl;

        for (size_t i = 0; i < MAX_ANIMALS; ++i)
            delete animals[i];
    }
    std::cout << std::endl;
    {
        std::cout << "================================="
                     " ASSIGN TESTS "
                     "================================="
                  << std::endl;
        Dog dog;
        std::cout << std::endl;

        Dog assign;
        assign = dog;
        std::cout << std::endl;

        assign.getBrain()->setIdea(0, "Changed this idea in assigned dog.");
        std::cout << "dog's type:                " << dog.getType() << "\n";
        std::cout << "dog's brain address:       " << dog.getBrain() << "\n";
        std::cout << "dog's ideas:\n" << *dog.getBrain() << "\n";
        std::cout << "assign's type:             " << assign.getType() << "\n";
        std::cout << "assign's brain address:    " << assign.getBrain() << "\n";
        std::cout << "assign's ideas:\n" << *assign.getBrain() << "\n";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "=================================="
                     " COPY TESTS "
                     "=================================="
                  << std::endl;
        Cat cat;
        std::cout << std::endl;

        Cat copy(cat);
        std::cout << std::endl;

        copy.getBrain()->setIdea(0, "Changed this idea in copied cat.");
        std::cout << "cat's type:                " << cat.getType() << "\n";
        std::cout << "cat's brain address:       " << cat.getBrain() << "\n";
        std::cout << "cat's ideas:\n" << *cat.getBrain() << "\n";
        std::cout << "copy's type:               " << copy.getType() << "\n";
        std::cout << "copy's brain address:      " << copy.getBrain() << "\n";
        std::cout << "copy's ideas:\n" << *copy.getBrain() << "\n";
        std::cout << std::endl;
    }
    return (0);
}
