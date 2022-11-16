/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:04:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/16 12:50:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);

        void announce(void);
        void setZombieName(std::string name);

    private:
        std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif /* ZOMBIE_H */
