/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:21 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 13:51:34 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {

    public:
        Dog(void);
        Dog(Dog const &src);
        ~Dog(void);

        Dog &operator=(Dog const &rhs);

        Brain *getBrain(void) const;

        void makeSound(void) const;

    private:
        Brain *_brain;
};

#endif /* DOG_H */
