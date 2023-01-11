/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:13:40 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/10 22:41:48 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <stdint.h>
#include <string>

struct Data
{
        Data(std::string const &data);
        std::string const data;
};

uintptr_t serialize(Data *ptr);
Data     *deserialize(uintptr_t raw);

#endif /* DATA_H */
