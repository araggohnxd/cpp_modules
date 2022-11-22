/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:29:42 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "cstring"

#define MAX_SLOTS 4

class Character : public ICharacter {
    public:
        Character(void);
        Character(Character const &src);
        Character(std::string const &name);
        ~Character(void);

        Character &operator=(Character const &rhs);

        std::string const &getName(void) const;
        void               equip(AMateria *m);
        void               unequip(int idx);
        void               use(int idx, ICharacter &target);

    private:
        std::string _name;
        AMateria   *_inventory[MAX_SLOTS];
};

#endif /* CHARACTER_H */
