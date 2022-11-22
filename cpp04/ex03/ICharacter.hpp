/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:22:29 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:23 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include <iostream>
#include <string>

class AMateria;

class ICharacter {
    public:
        virtual ~ICharacter(void) {};

        virtual std::string const &getName(void) const              = 0;
        virtual void               equip(AMateria *m)               = 0;
        virtual void               unequip(int idx)                 = 0;
        virtual void               use(int idx, ICharacter &target) = 0;
};

#endif /* ICHARACTER_H */
