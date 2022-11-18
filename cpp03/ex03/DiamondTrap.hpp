/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:57:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/18 16:05:10 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {

    public:
        DiamondTrap(void);
        DiamondTrap(DiamondTrap const &src);
        DiamondTrap(std::string name);
        ~DiamondTrap(void);

        DiamondTrap &operator=(DiamondTrap const &rhs);

        std::string getName(void) const;

        void whoAmI(void) const;

    private:
        std::string const _name;
};

#endif /* DIAMONDTRAP_H */
