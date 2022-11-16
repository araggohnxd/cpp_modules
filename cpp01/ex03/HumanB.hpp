/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:31:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/16 13:49:02 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
    public:
        HumanB(std::string name);
        ~HumanB(void);

        void attack() const;
        void setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon     *_weapon;
};

#endif /* HUMAN_B_HPP */
