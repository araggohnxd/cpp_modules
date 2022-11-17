/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:33:19 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/17 13:02:06 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>

class Fixed {
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        Fixed(int const n);
        Fixed(float const f);
        ~Fixed(void);

        Fixed &operator=(Fixed const &rhs);

        int  getRawBits(void) const;
        void setRawBits(int const raw);

        int   toInt(void) const;
        float toFloat(void) const;

    private:
        int              _rawBits;
        static const int _fractionalBits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif /* FIXED_H */
