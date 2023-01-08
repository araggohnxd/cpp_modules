/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:22:59 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/06 23:13:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

#define MIN_GRADE 150
#define MAX_GRADE 1

class AForm;

class Bureaucrat {
    public:
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const &src);
        Bureaucrat(std::string const name, int const grade);
        ~Bureaucrat(void);

        class GradeTooHighException : public std::exception {
                char const *what(void) const throw();
        };

        class GradeTooLowException : public std::exception {
                char const *what(void) const throw();
        };

        Bureaucrat &operator=(Bureaucrat const &rhs);

        std::string const getName(void) const;
        int               getGrade(void) const;

        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(AForm &form);
        void executeForm(AForm const &form);

    private:
        std::string const _name;
        int               _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif /* BUREAUCRAT_H */
