/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:30:47 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/14 23:24:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *array, size_t length, void (*f)(T &))
{
    for (size_t i = 0; i < length; ++i)
        f(array[i]);
}

#endif /* ITER_HPP */
