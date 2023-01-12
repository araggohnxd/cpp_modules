/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:00:03 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/11 23:03:51 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
    public:
        Array(void);
        Array(size_t n);
        Array(Array const &src);
        ~Array(void);

        Array   &operator=(Array const &rhs);
        T       &operator[](size_t i);
        T const &operator[](size_t i) const;

        size_t size(void) const;

    private:
        T     *_array;
        size_t _size;
};

#endif /* ARRAY_HPP */
