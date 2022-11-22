/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:04:02 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

    public:
        Ice(void);
        Ice(Ice const &src);
        Ice(std::string const &type);
        ~Ice(void);

        Ice &operator=(Ice const &rhs);

        Ice *clone(void) const;
        void use(ICharacter &target);
};

#endif /* ICE_H */
