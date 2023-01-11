/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:16:43 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/11 18:24:42 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
    T tmp;

    tmp = a;
    a   = b;
    b   = tmp;
}

template <typename T>
T min(T const &a, T const &b)
{
    return ((a < b) ? a : b);
}

template <typename T>
T max(T const &a, T const &b)
{
    return ((a > b) ? a : b);
}

#endif /* WHATEVER_HPP */
