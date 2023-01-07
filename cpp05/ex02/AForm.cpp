/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:09:37 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/06 23:13:40 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(void) :
    _name("undefined"),
    _gradeSign(MIN_GRADE),
    _gradeExec(MIN_GRADE),
    _signed(false)
{
    std::cout << "AForm " << this->_name
              << " has been created via default constructor" << std::endl;
}

AForm::AForm(AForm const &src) :
    _name(src._name),
    _gradeSign(src._gradeSign),
    _gradeExec(src._gradeExec),
    _signed(src._signed)
{
    std::cout << "AForm " << this->_name
              << " has been created via copy constructor" << std::endl;
}

AForm::AForm(std::string const name, int const sign, int const exec) :
    _name(name),
    _gradeSign(sign),
    _gradeExec(exec),
    _signed(false)
{
    if (this->_gradeSign > MIN_GRADE || this->_gradeExec > MIN_GRADE)
        throw GradeTooLowException();
    if (this->_gradeSign < MAX_GRADE || this->_gradeExec < MAX_GRADE)
        throw GradeTooHighException();
    std::cout << "AForm " << this->_name
              << " has been created via parametric constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm(void)
{
    std::cout << "AForm " << this->_name << " has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &AForm::operator=(AForm const &rhs)
{
    const_cast<std::string &>(this->_name) = rhs._name;
    const_cast<int &>(this->_gradeSign)    = rhs._gradeSign;
    const_cast<int &>(this->_gradeExec)    = rhs._gradeExec;
    this->_signed                          = rhs._signed;
    std::cout << "AForm assignment operator has been called" << std::endl;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
    std::cout << "AForm '" << i.getName() << "', target: " << i.getTarget()
              << ", sign grade: " << i.getGradeSign()
              << ", exec grade: " << i.getGradeExec()
              << ", signed: " << (i.getSigned() ? "true" : "false");
    return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeSign)
        throw GradeTooLowException();
    if (this->_signed == true)
        throw FormAlreadySignedException();
    this->_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->_gradeExec)
        throw AForm::GradeTooLowException();
    if (!this->_signed)
        throw AForm::FormIsNotSignedException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const AForm::getTarget(void) const { return (this->_target); }

std::string const AForm::getName(void) const { return (this->_name); }

int AForm::getGradeSign(void) const { return (this->_gradeSign); }

int AForm::getGradeExec(void) const { return (this->_gradeExec); }

bool AForm::getSigned(void) const { return (this->_signed); }

/*
** --------------------------------- MUTATOR ----------------------------------
*/

void AForm::setTarget(std::string const target)
{
    const_cast<std::string &>(this->_target) = target;
}

void AForm::setName(std::string const name)
{
    const_cast<std::string &>(this->_name) = name;
}

void AForm::setGradeSign(int const grade)
{
    const_cast<int &>(this->_gradeSign) = grade;
}

void AForm::setGradeExec(int const grade)
{
    const_cast<int &>(this->_gradeExec) = grade;
}

void AForm::setSigned(bool const sign)
{
    const_cast<bool &>(this->_signed) = sign;
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/

char const *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade in form is too high");
}

char const *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade in form is too low");
}

char const *AForm::FormAlreadySignedException::what(void) const throw()
{
    return ("This form is already signed");
}

char const *AForm::FormIsNotSignedException::what(void) const throw()
{
    return ("This form is not signed");
}
