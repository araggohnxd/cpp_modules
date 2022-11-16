/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:23:15 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/16 13:48:59 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);

        void attack(void) const;

    private:
        std::string _name;
        Weapon     &_weapon;
};

#endif /* HUMAN_A_HPP */
