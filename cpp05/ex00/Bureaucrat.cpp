/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:22:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/23 13:14:46 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(void) : _name("undefined"), _grade(MIN_GRADE)
{
    std::cout << "Bureaucrat " << this->_name
              << " has been created via default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) :
    _name(src._name),
    _grade(src._grade)
{
    std::cout << "Bureaucrat " << this->_name
              << " has been created via copy constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int const grade) :
    _name(name),
    _grade(grade)
{
    if (this->_grade > MIN_GRADE)
        throw GradeTooLowException();
    if (this->_grade < MAX_GRADE)
        throw GradeTooHighException();
    std::cout << "Bureaucrat " << this->_name
              << " has been created via parametric constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat " << this->_name << " has been destroyed"
              << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    const_cast<std::string &>(this->_name) = rhs._name;
    this->_grade                           = rhs._grade;
    std::cout << "Bureaucrat assignment operator has been called" << std::endl;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
    std::cout << "Bureaucrat " << i.getName() << ", grade " << i.getGrade();
    return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade(void)
{
    if (this->_grade <= MAX_GRADE)
        throw GradeTooHighException();
    --this->_grade;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->_grade >= MIN_GRADE)
        throw GradeTooLowException();
    ++this->_grade;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const Bureaucrat::getName(void) const { return (this->_name); }

int Bureaucrat::getGrade(void) const { return (this->_grade); }

/*
** --------------------------------- EXCEPTION --------------------------------
*/

char const *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Bureaucrat grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Bureaucrat grade is too low");
}
