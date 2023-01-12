/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:14:41 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/12 17:57:49 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

class Span {
    public:
        Span(void);
        Span(Span const &src);
        Span(size_t n);
        ~Span(void);

        Span &operator=(Span const &rhs);

        template <typename T>
        void addNumber(T begin, T end)
        {
            if ((_span.size() + std::distance(begin, end)) > _max)
                throw std::length_error("Range too big to fit this Span");
            _span.insert(_span.end(), begin, end);
        }
        void addNumber(int n);

        int shortestSpan(void);
        int longestSpan(void);

        std::vector<int> const &getSpan(void) const;
        size_t                  getMax(void) const;

    private:
        std::vector<int> _span;
        size_t           _max;
};

std::ostream &operator<<(std::ostream &o, Span const &i);

#endif /* SPAN_H */
