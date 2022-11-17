/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:33:12 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/17 13:02:09 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(int const n) : _rawBits(n << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f) : _rawBits(roundf(f * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(rhs.getRawBits());
    return (*this);
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

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits(void) const { return (this->_rawBits); }

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }
