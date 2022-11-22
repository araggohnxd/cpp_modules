/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:16:31 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:25 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
    public:
        virtual ~IMateriaSource(void) {}

        virtual void      learnMateria(AMateria *newMateria)     = 0;
        virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif /* IMATERIASOURCE_H */
