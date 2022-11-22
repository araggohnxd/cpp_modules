/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:17:49 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:32 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "cstring"

#define MAX_MATERIA 4

class MateriaSource : public IMateriaSource {

    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &src);
        ~MateriaSource(void);

        MateriaSource &operator=(MateriaSource const &rhs);

        void      learnMateria(AMateria *newMateria);
        AMateria *createMateria(std::string const &type);

    private:
        AMateria *_materia[MAX_MATERIA];
};

#endif /* MATERIASOURCE_H */
