/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:28:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/21 19:30:04 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {

    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const &src);
        ~WrongAnimal(void);

        WrongAnimal &operator=(WrongAnimal const &rhs);

        std::string getType(void) const;

        void makeSound(void) const;

    protected:
        std::string _type;
};

#endif /* WRONGANIMAL_H */
