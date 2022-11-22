/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:52:09 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 15:05:56 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain(void)
{
    std::string const ideas[24]
        = {"A bear's strength is its joy. Its joy is strength.",
           "I do not channel the demigods.",
           "Following instinct alone is no way to live.",
           "Bodies are not vessels. They are anchors.",
           "A stagnant Freljord is a dead Freljord.",
           "For many years I thought I was cursed. I still wonder.",
           "The Seal Sister blesses with water and salt.",
           "Twice I have loved, twice I have left.",
           "Great Seal Sister, guide my steps through treacherous waters.",
           "Peace is not balance here.",
           "I did not truly know the Freljord until I left it.",
           "I do not fight alone.",
           "My time in Ionia taught me control.",
           "I am of no tribe.",
           "I channel the spirits I feel closest to.",
           "Joy and strength both crackle through me.",
           "Demigods cannot be trusted with balance.",
           "This life is my burden, and my land's blessing.",
           "The Winter's Claw was never my home.",
           "Ordinary lives hold beauty.",
           "Weapons are for the weak.",
           "Animals act on instinct, not choice.",
           "Creatures of the Freljord walk in the footprints of the demigods.",
           "I did not think I would like being an oathfather."};

    for (size_t i = 0; i < MAX_IDEAS; ++i)
        this->_ideas[i] = ideas[std::rand() % 24];
    std::cout << "Brain has been created via default constructor" << std::endl;
}

Brain::Brain(const Brain &src)
{
    for (size_t i = 0; i < MAX_IDEAS; ++i)
        this->_ideas[i] = src._ideas[i];
    std::cout << "Brain has been created via copy constructor" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain(void) { std::cout << "Brain has been destroyed" << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &Brain::operator=(Brain const &rhs)
{
    for (size_t i = 0; i < MAX_IDEAS; ++i)
        this->_ideas[i] = rhs._ideas[i];
    return (*this);
}

std::ostream &operator<<(std::ostream &o, Brain const &i)
{
    for (size_t index = 0; index < 5; ++index)
        o << i.getIdea(index) << std::endl;
    return (o);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Brain::getIdea(size_t const i) const { return (this->_ideas[i]); }

/*
** ---------------------------------- MUTATOR ----------------------------------
*/

void Brain::setIdea(size_t const i, std::string const idea)
{
    this->_ideas[i] = idea;
}
