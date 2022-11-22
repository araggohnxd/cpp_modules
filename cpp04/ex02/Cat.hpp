/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:21 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 15:06:09 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public AAnimal {

    public:
        Cat(void);
        Cat(Cat const &src);
        ~Cat(void);

        Cat &operator=(Cat const &rhs);

        Brain *getBrain(void) const;

        void makeSound(void) const;

    private:
        Brain *_brain;
};

#endif /* CAT_H */
