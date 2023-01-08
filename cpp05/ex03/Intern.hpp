/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:28:51 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/07 00:06:37 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

#define MAX_FORMS     3
#define SCF_FORM_NAME "shrubbery creation"
#define RRF_FORM_NAME "robotomy request"
#define PPF_FORM_NAME "presidential pardon"

class Intern {

    public:
        Intern(void);
        Intern(Intern const &src);
        ~Intern(void);

        class FormNotFoundException : public std::exception {
                char const *what(void) const throw();
        };

        AForm *makeForm(std::string const &name, std::string const &target);

        Intern &operator=(Intern const &rhs);

    private:
        AForm *_makeShrubberyCreationForm(std::string const &target);
        AForm *_makeRobotomyRequestForm(std::string const &target);
        AForm *_makePresidentialPardonForm(std::string const &target);
};

#endif /* INTERN_H */
