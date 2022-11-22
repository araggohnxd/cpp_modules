/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:28:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 15:05:53 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {

    public:
        AAnimal(void);
        AAnimal(AAnimal const &src);
        virtual ~AAnimal(void);

        AAnimal &operator=(AAnimal const &rhs);

        std::string getType(void) const;

        virtual void makeSound(void) const = 0;

    protected:
        std::string _type;
};

#endif /* AANIMAL_H */
