/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:46:28 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/23 20:25:34 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "=== Create 'Food garments' form ===" << '\n';
    Form food("Food garments", 50, 10);
    std::cout << '\n';

    std::cout << "=== Status of a recently created form ===" << '\n'
              << food << "\n\n";

    std::cout << "=== Create some bureaucrats ===" << '\n';
    Bureaucrat jim("Jim", 100), bob("Bob", 50), tom("Tom", 1);
    std::cout << '\n';

    std::cout << "=== Try to sign form with incorrect grade ===" << '\n';
    jim.signForm(food);
    std::cout << '\n';

    std::cout << "=== Try to sign form with correct grade ===" << '\n';
    bob.signForm(food);
    std::cout << '\n';

    std::cout << "=== Try to sign an already signed form ===" << '\n';
    tom.signForm(food);
    std::cout << '\n';

    std::cout << "=== Status of an already signed form ===" << '\n'
              << food << "\n\n";

    std::cout << "=== Try to create form with grade above maximum ===" << '\n';
    try {
        Form wage("wage", 50, 0);
    } catch (std::exception const &e) {
        std::cerr << "Couldn't create form: " << e.what() << '\n';
    }
    std::cout << '\n';

    std::cout << "=== Try to create form with grade below minimum ===" << '\n';
    try {
        Form cloth("cloth", 500, 10);
    } catch (std::exception const &e) {
        std::cerr << "Couldn't create form: " << e.what() << '\n';
    }
    std::cout << std::endl;
    return (0);
}
