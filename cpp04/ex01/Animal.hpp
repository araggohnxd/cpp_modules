/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:28:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 13:51:38 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

    public:
        Animal(void);
        Animal(Animal const &src);
        virtual ~Animal(void);

        Animal &operator=(Animal const &rhs);

        std::string getType(void) const;

        virtual void makeSound(void) const;

    protected:
        std::string _type;
};

#endif /* ANIMAL_H */
