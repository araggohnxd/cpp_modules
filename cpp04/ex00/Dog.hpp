/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:21 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/21 19:20:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {

    public:
        Dog(void);
        Dog(Dog const &src);
        ~Dog(void);

        Dog &operator=(Dog const &rhs);

        void makeSound(void) const;
};

#endif /* DOG_H */
