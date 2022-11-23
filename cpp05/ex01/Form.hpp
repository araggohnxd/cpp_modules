/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:09:38 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/23 20:25:48 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
    public:
        Form(void);
        Form(Form const &src);
        Form(std::string const name, int const sign, int const exec);
        ~Form(void);

        class GradeTooHighException : public std::exception {
                char const *what(void) const throw();
        };

        class GradeTooLowException : public std::exception {
                char const *what(void) const throw();
        };

        class FormAlreadySigned : public std::exception {
                char const *what(void) const throw();
        };

        Form &operator=(Form const &rhs);

        std::string const getName(void) const;
        int               getGradeSign(void) const;
        int               getGradeExec(void) const;
        bool              getSigned(void) const;

        void beSigned(Bureaucrat const &bureaucrat);

    private:
        std::string const _name;
        int const         _gradeSign;
        int const         _gradeExec;
        bool              _signed;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif /* FORM_H */
