/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:04:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/16 12:26:35 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    public:
        Zombie(std::string name);
        ~Zombie(void);

        void announce(void);

    private:
        std::string const _name;
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif /* ZOMBIE_H */
