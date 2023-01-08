/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:35:26 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/06 23:13:51 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PPF::PresidentialPardonForm(void) :
    AForm("PresidentialPardonForm", PPF_SIGN_GRADE, PPF_EXEC_GRADE)
{
    this->setTarget("undefined");
    std::cout
        << "PresidentialPardonForm has been created via default constructor"
        << std::endl;
}

PPF::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
    this->setTarget(src._target);
    this->setName(src.getName());
    this->setGradeSign(src.getGradeSign());
    this->setGradeExec(src.getGradeExec());
    this->setSigned(src.getSigned());
    std::cout << "PresidentialPardonForm has been created via copy constructor"
              << std::endl;
}

PPF::PresidentialPardonForm(std::string const &target) :
    AForm("PresidentialPardonForm", PPF_SIGN_GRADE, PPF_EXEC_GRADE)
{
    this->setTarget(target);
    std::cout
        << "PresidentialPardonForm has been created via parametric constructor"
        << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PPF::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &PPF::operator=(PresidentialPardonForm const &rhs)
{
    this->setTarget(rhs._target);
    this->setName(rhs.getName());
    this->setGradeSign(rhs.getGradeSign());
    this->setGradeExec(rhs.getGradeExec());
    this->setSigned(rhs.getSigned());
    std::cout << "PresidentialPardonForm assignment operator has been called"
              << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PPF::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << this->_target
              << " has been pardoned by Mr. President Zaphod Beeblebrox"
              << std::endl;
}
