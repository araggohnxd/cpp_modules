/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:33:19 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/17 18:32:31 by maolivei         ###   ########.fr       */
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

        bool operator==(Fixed const &rhs) const;
        bool operator!=(Fixed const &rhs) const;
        bool operator>=(Fixed const &rhs) const;
        bool operator<=(Fixed const &rhs) const;
        bool operator>(Fixed const &rhs) const;
        bool operator<(Fixed const &rhs) const;

        Fixed &operator=(Fixed const &rhs);
        Fixed  operator+(Fixed const &rhs);
        Fixed  operator-(Fixed const &rhs);
        Fixed  operator*(Fixed const &rhs);
        Fixed  operator/(Fixed const &rhs);

        Fixed &operator++(void); /* prefixed */
        Fixed  operator++(int);  /* postfixed */
        Fixed &operator--(void); /* prefixed */
        Fixed  operator--(int);  /* postfixed */

        static Fixed       &min(Fixed &lhs, Fixed &rhs);
        static const Fixed &min(Fixed const &lhs, Fixed const &rhs);
        static Fixed       &max(Fixed &lhs, Fixed &rhs);
        static const Fixed &max(Fixed const &lhs, Fixed const &rhs);

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
