/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:28:50 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/07 00:11:08 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern(void)
{
    std::cout << "Intern has been created via default constructor" << std::endl;
}

Intern::Intern(Intern const &src)
{
    (void)src;
    std::cout << "Intern has been created via copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern(void) { std::cout << "Intern has been destroyed" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    std::string forms[MAX_FORMS]
        = {SCF_FORM_NAME, RRF_FORM_NAME, PPF_FORM_NAME};

    AForm *(Intern::*handlers[MAX_FORMS])(std::string const &)
        = {&Intern::_makeShrubberyCreationForm,
           &Intern::_makeRobotomyRequestForm,
           &Intern::_makePresidentialPardonForm};

    for (size_t i = 0; i < MAX_FORMS; ++i) {
        if (name == forms[i]) {
            std::cout << "Intern creates " << name << ", with '" << target
                      << "' as target" << std::endl;
            return ((this->*handlers[i])(target));
        }
    }
    throw FormNotFoundException();
}

AForm *Intern::_makeShrubberyCreationForm(std::string const &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::_makeRobotomyRequestForm(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::_makePresidentialPardonForm(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/

char const *Intern::FormNotFoundException::what(void) const throw()
{
    return ("Requested form does not exist");
}
