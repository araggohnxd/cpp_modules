/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:42:26 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/12 13:52:46 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &haystack, int needle)
{
    typename T::iterator it
        = std::find(haystack.begin(), haystack.end(), needle);

    if (it == haystack.end())
        throw std::runtime_error("Integer not found inside container");
    return (it);
}

#endif /* EASYFIND_HPP */
