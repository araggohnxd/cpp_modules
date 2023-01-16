/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:33:12 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/15 22:14:26 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(Fixed const &src) : _rawBits(src._rawBits) {}

Fixed::Fixed(int const n) : _rawBits(n << _fractionalBits) {}

Fixed::Fixed(float const f) : _rawBits(roundf(f * (1 << _fractionalBits))) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed(void) {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

bool Fixed::operator==(Fixed const &rhs) const
{
    return (this->_rawBits == rhs._rawBits);
}

bool Fixed::operator!=(Fixed const &rhs) const
{
    return (this->_rawBits != rhs._rawBits);
}

bool Fixed::operator>=(Fixed const &rhs) const
{
    return (this->_rawBits >= rhs._rawBits);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
    return (this->_rawBits <= rhs._rawBits);
}

bool Fixed::operator>(Fixed const &rhs) const
{
    return (this->_rawBits > rhs._rawBits);
}

bool Fixed::operator<(Fixed const &rhs) const
{
    return (this->_rawBits < rhs._rawBits);
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    this->_rawBits = rhs._rawBits;
    return (*this);
}

Fixed Fixed::operator+(Fixed const &rhs)
{
    Fixed aux(this->toFloat() + rhs.toFloat());

    return (aux);
}

Fixed Fixed::operator-(Fixed const &rhs)
{
    Fixed aux(this->toFloat() - rhs.toFloat());

    return (aux);
}

Fixed Fixed::operator*(Fixed const &rhs)
{
    Fixed aux(this->toFloat() * rhs.toFloat());

    return (aux);
}

Fixed Fixed::operator/(Fixed const &rhs)
{
    Fixed aux(this->toFloat() / rhs.toFloat());

    return (aux);
}

Fixed &Fixed::operator++(void)
{
    ++this->_rawBits;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed aux = *this;

    this->_rawBits++;
    return (aux);
}

Fixed &Fixed::operator--(void)
{
    --this->_rawBits;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed aux = *this;

    this->_rawBits--;
    return (aux);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
    o << i.toFloat();
    return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int Fixed::toInt(void) const { return (this->_rawBits >> _fractionalBits); }

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_rawBits) / (1 << _fractionalBits));
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
    return (lhs._rawBits < rhs._rawBits ? lhs : rhs);
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
    return (lhs._rawBits < rhs._rawBits ? lhs : rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
    return (lhs._rawBits > rhs._rawBits ? lhs : rhs);
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
    return (lhs._rawBits > rhs._rawBits ? lhs : rhs);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const { return (this->_rawBits); }

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }
