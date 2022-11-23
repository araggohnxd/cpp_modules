/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:46:28 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/23 13:06:35 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "=============================="
                 " INVALID OPERATIONS "
                 "=============================="
              << std::endl;
    try {
        std::cout << "=== Instantiate bureaucrat with grade 151 ===\n";
        Bureaucrat jim("Jim", 151);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << "=== Instantiate bureaucrat with grade 0 ===\n";
        Bureaucrat jim("Jim", 0);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << "=== Decrement grade below minimum ===\n";
        Bureaucrat jim("Jim", 150);
        jim.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << "=== Increment grade above maximum ===\n";
        Bureaucrat jim("Jim", 1);
        jim.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << "=== Decrement grade below minimum (default ctor) ===\n";
        Bureaucrat jim;
        jim.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "==============================="
                 " VALID OPERATIONS "
                 "==============================="
              << std::endl;
    try {
        std::cout << "=== Decrement grade within allowed range ===\n";
        Bureaucrat jim("Jim", 1);
        jim.decrementGrade();
        std::cout << jim << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << "=== Increment grade within allowed range ===\n";
        Bureaucrat jim("Jim", 150);
        jim.incrementGrade();
        std::cout << jim << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
