/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:09:23 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:11 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria {
    public:
        AMateria(void);
        AMateria(AMateria const &src);
        AMateria(std::string const &type);
        virtual ~AMateria(void);

        AMateria &operator=(AMateria const &rhs);

        std::string const &getType(void) const;

        virtual AMateria *clone(void) const = 0;
        virtual void      use(ICharacter &target);

    protected:
        std::string _type;
};

#endif /* AMATERIA_H */
