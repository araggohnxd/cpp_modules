/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:34:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/16 19:55:03 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::complain(std::string level)
{
    size_t      index;
    std::string levels[MAX_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*f[MAX_LEVELS])(void)
        = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (index = 0; index < MAX_LEVELS; ++index)
        if (level == levels[index])
            break;
    switch (index) {
        case (0):
            (this->*f[index++])();
            std::cout << std::endl;
            // fall through
        case (1):
            (this->*f[index++])();
            std::cout << std::endl;
            // fall through
        case (2):
            (this->*f[index++])();
            std::cout << std::endl;
            // fall through
        case (3):
            (this->*f[index])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
            break;
    }
}

void Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl
              << "I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
              << "I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]" << std::endl
              << "I cannot believe adding extra bacon costs more money. "
              << "You didn't put enough bacon in my burger! "
              << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl
              << "I think I deserve to have some extra bacon for free. "
              << "I've been coming for years whereas you started working here "
              << "since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl
              << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}
