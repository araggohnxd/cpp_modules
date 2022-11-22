/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:04:02 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:17 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {

    public:
        Cure(void);
        Cure(Cure const &src);
        Cure(std::string const &type);
        ~Cure(void);

        Cure &operator=(Cure const &rhs);

        Cure *clone(void) const;
        void  use(ICharacter &target);
};

#endif /* CURE_H */
