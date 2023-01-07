/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:35:27 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/06 23:14:01 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

#define SCF_TREE                                                               \
 "\
                     . . .\n\
                   .        .  .     ..    .\n\
                .                 .         .  .\n\
               .      .         .       .\n\
                .               .           .    ..\n\
               .          .            .              .\n\
               .      .     '.,        .       .        .\n\
               .              'b      *    .\n\
                .        .     '$    #.        .       ..\n\
               .    .           $:   #:      .         .\n\
             ..      .  ..      *#  @):        .   . .\n\
                          .     :@,@):   ,.**:'   .\n\
              .      .,         :@@*: ..**'      .   .\n\
                       '#o.    .:(@'.@*''  .\n\
               .  .       'bq,..:,@@*'   ,*      .  .\n\
                          ,p$q8,:@)'  .p*'      .\n\
                   .     '  . '@@Pp@@*'    .  .\n\
                    .  . ..    Y7'.'     .  .\n\
                              :@):.\n\
                             .:@:'.\n\
                           .::(@:.\n\
"

#define SCF_SIGN_GRADE 145
#define SCF_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm {

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ShrubberyCreationForm(std::string const &target);
        ~ShrubberyCreationForm(void);

        class FileCreateErrorException : public std::exception {
                char const *what(void) const throw();
        };

        class FileWriteErrorException : public std::exception {
                char const *what(void) const throw();
        };

        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

        void execute(Bureaucrat const &executor) const;
};

typedef ShrubberyCreationForm SCF;

#endif /* SHRUBBERY_CREATION_FORM_H */
