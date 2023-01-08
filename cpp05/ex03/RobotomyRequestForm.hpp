/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:35:27 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/06 23:13:57 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

#define RRF_SIGN_GRADE 72
#define RRF_EXEC_GRADE 45

class RobotomyRequestForm : public AForm {

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        RobotomyRequestForm(std::string const &target);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

        void execute(Bureaucrat const &executor) const;
};

typedef RobotomyRequestForm RRF;

#endif /* ROBOTOMY_REQUEST_FORM_H */
