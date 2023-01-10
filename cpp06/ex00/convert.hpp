/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:26:51 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/10 20:02:38 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
#define CONVERT_H

#include <cfloat>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>

int  convert(std::string &str);
int  specialCases(std::string const &str);
void printError(std::string &str);
void printSingleChar(std::string::iterator const &it);
void printNumber(std::string &str);
void handleWhitespaces(char &c);

#endif /* CONVERT_H */
