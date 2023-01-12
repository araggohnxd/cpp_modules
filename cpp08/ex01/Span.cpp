/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:14:39 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/12 17:57:44 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(void) : _span(std::vector<int>()), _max(0) {}

Span::Span(size_t n) : _span(std::vector<int>()), _max(n) {}

Span::Span(Span const &src) : _span(std::vector<int>(src._span)), _max(src._max)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span(void) {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &Span::operator=(Span const &rhs)
{
    if (this != &rhs) {
        _span = rhs._span;
        _max  = rhs._max;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Span const &i)
{
    std::vector<int>::iterator it;
    std::vector<int>           tmp;

    std::cout << "Span maximum capacity: " << i.getMax() << '\n';
    tmp = i.getSpan();
    std::cout << "Span items:";
    for (it = tmp.begin(); it < tmp.end(); it++)
        std::cout << ' ' << *it;
    return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int n)
{
    if (_span.size() >= _max)
        throw std::length_error("Span is already full");
    _span.push_back(n);
}

int Span::shortestSpan(void)
{
    std::vector<int>::iterator it;
    int                        shortestSpan, diff;

    if (_span.size() < 2)
        throw std::length_error("Span must have at least 2 elements");
    std::sort(_span.begin(), _span.end());
    shortestSpan = _span.back() - _span.front();
    for (it = _span.begin(); it < _span.end() - 1; ++it) {
        diff = *(it + 1) - *it;
        if (diff < shortestSpan)
            shortestSpan = diff;
    }
    return (shortestSpan);
}

int Span::longestSpan(void)
{
    int min, max;

    if (_span.size() < 2)
        throw std::length_error("Span must have at least 2 elements");
    min = *std::min_element(_span.begin(), _span.end());
    max = *std::max_element(_span.begin(), _span.end());
    return (max - min);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::vector<int> const &Span::getSpan(void) const { return (this->_span); }

size_t Span::getMax(void) const { return (this->_max); }
