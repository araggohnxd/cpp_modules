/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:33:19 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/17 12:03:20 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        ~Fixed(void);

        Fixed &operator=(Fixed const &rhs);

        int  getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int              _rawBits;
        static const int _fractionalBits;
};

#endif /* FIXED_H */
