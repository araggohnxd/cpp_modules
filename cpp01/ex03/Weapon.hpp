/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:18:21 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/16 13:48:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
    public:
        Weapon(std::string type);
        ~Weapon(void);

        std::string getType(void) const;
        void        setType(std::string type);

    private:
        std::string _type;
};

#endif /* WEAPON_HPP */
