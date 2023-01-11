/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:13:39 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/10 22:41:46 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Data::Data(std::string const &data) : data(data) {}

/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t serialize(Data *ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

Data *deserialize(uintptr_t raw) { return (reinterpret_cast<Data *>(raw)); }
