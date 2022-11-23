/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:09:37 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/23 20:25:51 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(void) :
    _name("undefined"),
    _gradeSign(MIN_GRADE),
    _gradeExec(MIN_GRADE),
    _signed(false)
{
    std::cout << "Form " << this->_name
              << " has been created via default constructor" << std::endl;
}

Form::Form(Form const &src) :
    _name(src._name),
    _gradeSign(src._gradeSign),
    _gradeExec(src._gradeExec),
    _signed(src._signed)
{
    std::cout << "Form " << this->_name
              << " has been created via copy constructor" << std::endl;
}

Form::Form(std::string const name, int const sign, int const exec) :
    _name(name),
    _gradeSign(sign),
    _gradeExec(exec),
    _signed(false)
{
    if (this->_gradeSign > MIN_GRADE || this->_gradeExec > MIN_GRADE)
        throw GradeTooLowException();
    if (this->_gradeSign < MAX_GRADE || this->_gradeExec < MAX_GRADE)
        throw GradeTooHighException();
    std::cout << "Form " << this->_name
              << " has been created via parametric constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form(void)
{
    std::cout << "Form " << this->_name << " has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{
    const_cast<std::string &>(this->_name) = rhs._name;
    const_cast<int &>(this->_gradeSign)    = rhs._gradeSign;
    const_cast<int &>(this->_gradeExec)    = rhs._gradeExec;
    this->_signed                          = rhs._signed;
    std::cout << "Form assignment operator has been called" << std::endl;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
    std::cout << "Form '" << i.getName()
              << "', sign grade: " << i.getGradeSign()
              << ", exec grade: " << i.getGradeExec()
              << ", signed: " << (i.getSigned() ? "true" : "false");
    return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeSign)
        throw GradeTooLowException();
    if (this->_signed == true)
        throw FormAlreadySigned();
    this->_signed = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const Form::getName(void) const { return (this->_name); }

int Form::getGradeSign(void) const { return (this->_gradeSign); }

int Form::getGradeExec(void) const { return (this->_gradeExec); }

bool Form::getSigned(void) const { return (this->_signed); }

/*
** --------------------------------- EXCEPTION --------------------------------
*/

char const *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade in form is too high");
}

char const *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade in form is too low");
}

char const *Form::FormAlreadySigned::what(void) const throw()
{
    return ("This form is already signed");
}
