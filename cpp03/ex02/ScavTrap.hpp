/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:57:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/18 13:17:32 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap {

    public:
        ScavTrap(void);
        ScavTrap(ScavTrap const &src);
        ScavTrap(std::string name);
        ~ScavTrap(void);

        ScavTrap &operator=(ScavTrap const &rhs);

        void guardGate(void);
};

#endif /* SCAVTRAP_H */
