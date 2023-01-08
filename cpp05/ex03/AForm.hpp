/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:09:38 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/06 23:13:42 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
    public:
        AForm(void);
        AForm(AForm const &src);
        AForm(std::string const name, int const sign, int const exec);
        virtual ~AForm(void);

        class GradeTooHighException : public std::exception {
                char const *what(void) const throw();
        };

        class GradeTooLowException : public std::exception {
                char const *what(void) const throw();
        };

        class FormAlreadySignedException : public std::exception {
                char const *what(void) const throw();
        };

        class FormIsNotSignedException : public std::exception {
                char const *what(void) const throw();
        };

        AForm &operator=(AForm const &rhs);

        std::string const getTarget(void) const;
        std::string const getName(void) const;
        int               getGradeSign(void) const;
        int               getGradeExec(void) const;
        bool              getSigned(void) const;

        void         beSigned(Bureaucrat const &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;

    protected:
        void setTarget(std::string const target);
        void setName(std::string const name);
        void setGradeSign(int const grade);
        void setGradeExec(int const grade);
        void setSigned(bool const sign);

        std::string const _target;

    private:
        std::string const _name;
        int const         _gradeSign;
        int const         _gradeExec;
        bool              _signed;
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif /* AFORM_H */
