/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:33:12 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/17 14:58:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const Fixed &src) : _rawBits(src.getRawBits()) {}

Fixed::Fixed(int const n) : _rawBits(n << _fractionalBits) {}

Fixed::Fixed(float const f) : _rawBits(roundf(f * (1 << _fractionalBits))) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

bool Fixed::operator==(Fixed const &rhs) const
{
    return (this->_rawBits == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const
{
    return (this->_rawBits != rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const
{
    return (this->_rawBits >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const
{
    return (this->_rawBits <= rhs.getRawBits());
}

bool Fixed::operator>(Fixed const &rhs) const
{
    return (this->_rawBits > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const
{
    return (this->_rawBits < rhs.getRawBits());
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    this->_rawBits = rhs.getRawBits();
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

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
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
    return (lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs);
}

const Fixed &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
    return (lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
    return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}

const Fixed &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
    return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const { return (this->_rawBits); }

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }
