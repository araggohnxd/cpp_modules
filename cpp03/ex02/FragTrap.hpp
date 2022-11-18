/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:57:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/18 13:26:37 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap {

    public:
        FragTrap(void);
        FragTrap(FragTrap const &src);
        FragTrap(std::string name);
        ~FragTrap(void);

        FragTrap &operator=(FragTrap const &rhs);

        void highFivesGuys(void);
};

#endif /* FRAGTRAP_H */
