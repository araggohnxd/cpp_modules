/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:12:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/17 18:34:44 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <string>

#ifdef __FLT_EPSILON__
# define EPSILON __FLT_EPSILON__
#else
# define EPSILON 1.19209290e-7F
#endif

class Point {

    public:
        Point(void);
        Point(Point const &src);
        Point(float const x, float const y);
        ~Point(void);

        Point &operator=(Point const &rhs);

        Fixed getX(void) const;
        Fixed getY(void) const;

    private:
        const Fixed _x;
        const Fixed _y;
};

#endif /* POINT_H */
