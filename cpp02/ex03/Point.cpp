/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:12:02 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/17 18:30:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point(void) : _x(0), _y(0) {}

Point::Point(Point const &src) : _x(src.getX()), _y(src.getY()) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point(void) {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &Point::operator=(Point const &rhs)
{
    const_cast<Fixed &>(this->_x) = rhs.getX();
    const_cast<Fixed &>(this->_y) = rhs.getY();
    return (*this);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Fixed Point::getX(void) const { return (this->_x); }

Fixed Point::getY(void) const { return (this->_y); }
