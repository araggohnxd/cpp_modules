/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:52:10 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 15:06:02 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <cstdlib>
#include <iostream>
#include <string>

#define MAX_IDEAS 100

class Brain {

    public:
        Brain(void);
        Brain(Brain const &src);
        ~Brain(void);

        Brain &operator=(Brain const &rhs);

        std::string getIdea(size_t const i) const;
        void        setIdea(size_t const i, std::string const idea);

    private:
        std::string _ideas[MAX_IDEAS];
};

std::ostream &operator<<(std::ostream &o, Brain const &i);

#endif /* BRAIN_H */
