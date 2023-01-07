/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:46:28 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/06 23:13:50 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    std::srand(time(NULL));
    std::cout << "===============================" << std::endl;
    std::cout << "=== SHRUBBERY CREATION FORM ===" << std::endl;
    std::cout << "===============================" << std::endl;
    {
        SCF        scf("home");
        Bureaucrat bob("Bob", 1), jon("Jon", 140), tim("Tim", 150);

        std::cout << '\n';
        std::cout << bob << '\n' << jon << '\n' << tim << '\n' << scf << '\n';
        std::cout << '\n';
        tim.signForm(scf);
        tim.executeForm(scf);
        std::cout << '\n';
        jon.signForm(scf);
        jon.executeForm(scf);
        std::cout << '\n';
        bob.executeForm(scf);
        std::cout << '\n';
    }
    std::cout << "\n=============================" << std::endl;
    std::cout << "=== ROBOTOMY REQUEST FORM ===" << std::endl;
    std::cout << "=============================" << std::endl;
    {
        RRF        rrf("Minion");
        Bureaucrat pip("Pip", 1), ted("Ted", 60), axl("Axl", 150);

        std::cout << '\n';
        std::cout << pip << '\n' << ted << '\n' << axl << '\n' << rrf << '\n';
        std::cout << '\n';
        axl.signForm(rrf);
        axl.executeForm(rrf);
        std::cout << '\n';
        ted.signForm(rrf);
        ted.executeForm(rrf);
        std::cout << '\n';
        pip.executeForm(rrf);
        pip.executeForm(rrf);
        pip.executeForm(rrf);
        pip.executeForm(rrf);
        pip.executeForm(rrf);
        std::cout << '\n';
    }
    std::cout << "\n================================" << std::endl;
    std::cout << "=== PRESIDENTIAL PARDON FORM ===" << std::endl;
    std::cout << "================================" << std::endl;
    {
        PPF        ppf("Sirius Black");
        Bureaucrat tyr("Tyr", 1), edd("Edd", 20), dre("Dre", 150);

        std::cout << '\n';
        std::cout << tyr << '\n' << edd << '\n' << dre << '\n' << ppf << '\n';
        std::cout << '\n';
        dre.signForm(ppf);
        dre.executeForm(ppf);
        std::cout << '\n';
        edd.signForm(ppf);
        edd.executeForm(ppf);
        std::cout << '\n';
        tyr.executeForm(ppf);
        std::cout << '\n';
    }
    return (0);
}
