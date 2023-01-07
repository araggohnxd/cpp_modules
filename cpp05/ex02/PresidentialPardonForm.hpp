/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:35:27 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/06 23:13:53 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

#define PPF_SIGN_GRADE 25
#define PPF_EXEC_GRADE 5

class PresidentialPardonForm : public AForm {

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        PresidentialPardonForm(std::string const &target);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

        void execute(Bureaucrat const &executor) const;
};

typedef PresidentialPardonForm PPF;

#endif /* PRESIDENTIAL_PARDON_FORM_H */
