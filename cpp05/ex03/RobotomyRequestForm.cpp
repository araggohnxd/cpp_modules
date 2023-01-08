/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:35:26 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/06 23:13:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RRF::RobotomyRequestForm(void) :
    AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXEC_GRADE)
{
    this->setTarget("undefined");
    std::cout << "RobotomyRequestForm has been created via default constructor"
              << std::endl;
}

RRF::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
    this->setTarget(src._target);
    this->setName(src.getName());
    this->setGradeSign(src.getGradeSign());
    this->setGradeExec(src.getGradeExec());
    this->setSigned(src.getSigned());
    std::cout << "RobotomyRequestForm has been created via copy constructor"
              << std::endl;
}

RRF::RobotomyRequestForm(std::string const &target) :
    AForm("RobotomyRequestForm", RRF_SIGN_GRADE, RRF_EXEC_GRADE)
{
    this->setTarget(target);
    std::cout
        << "RobotomyRequestForm has been created via parametric constructor"
        << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RRF::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &RRF::operator=(RobotomyRequestForm const &rhs)
{
    this->setTarget(rhs._target);
    this->setName(rhs.getName());
    this->setGradeSign(rhs.getGradeSign());
    this->setGradeExec(rhs.getGradeExec());
    this->setSigned(rhs.getSigned());
    std::cout << "RobotomyRequestForm assignment operator has been called"
              << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RRF::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << "*DRILLING NOISES*" << std::endl;
    if (std::rand() % 2)
        std::cout << this->_target << " has been succesfully robotomized"
                  << std::endl;
    else
        std::cout << this->_target << "'s robotomy has failed" << std::endl;
}
