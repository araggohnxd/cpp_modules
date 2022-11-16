/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:34:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/16 19:17:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::complain(std::string level)
{
    std::string levels[MAX_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*f[MAX_LEVELS])(void)
        = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (size_t i = 0; i < MAX_LEVELS; ++i)
        if (level == levels[i])
            return ((this->*f[i])());
    std::cerr << level << " is an invalid option!" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "[DEBUG] "
                 "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. "
                 "I really do!"
              << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO] "
                 "I cannot believe adding extra bacon costs more money. "
                 "You didn't put enough bacon in my burger! "
                 "If you did, I wouldn't be asking for more!"
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING] "
                 "I think I deserve to have some extra bacon for free. "
                 "I've been coming for years whereas you started working here "
                 "since last month."
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR] "
                 "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}
