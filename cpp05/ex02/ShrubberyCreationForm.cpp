/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:35:26 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/06 23:13:58 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

SCF::ShrubberyCreationForm(void) :
    AForm("ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXEC_GRADE)
{
    this->setTarget("undefined");
    std::cout
        << "ShrubberyCreationForm has been created via default constructor"
        << std::endl;
}

SCF::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
    this->setTarget(src._target);
    this->setName(src.getName());
    this->setGradeSign(src.getGradeSign());
    this->setGradeExec(src.getGradeExec());
    this->setSigned(src.getSigned());
    std::cout << "ShrubberyCreationForm has been created via copy constructor"
              << std::endl;
}

SCF::ShrubberyCreationForm(std::string const &target) :
    AForm("ShrubberyCreationForm", SCF_SIGN_GRADE, SCF_EXEC_GRADE)
{
    this->setTarget(target);
    std::cout
        << "ShrubberyCreationForm has been created via parametric constructor"
        << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

SCF::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm has been destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &SCF::operator=(ShrubberyCreationForm const &rhs)
{
    this->setTarget(rhs._target);
    this->setName(rhs.getName());
    this->setGradeSign(rhs.getGradeSign());
    this->setGradeExec(rhs.getGradeExec());
    this->setSigned(rhs.getSigned());
    std::cout << "ShrubberyCreationForm assignment operator has been called"
              << std::endl;
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void SCF::execute(Bureaucrat const &executor) const
{
    std::string   filename;
    std::ofstream outfile;

    AForm::execute(executor);
    filename = this->getTarget() + "_shrubbery";
    outfile.open(filename.c_str(), std::fstream::out | std::fstream::trunc);
    if (outfile.fail())
        throw FileCreateErrorException();
    outfile << SCF_TREE;
    if (outfile.bad())
        throw FileWriteErrorException();
    outfile.close();
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/

char const *SCF::FileCreateErrorException::what(void) const throw()
{
    return ("Could not create shrubbery file");
}

char const *SCF::FileWriteErrorException::what(void) const throw()
{
    return ("Could not write in shrubbery file");
}
