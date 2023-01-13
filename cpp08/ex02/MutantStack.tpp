/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:04:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/12 23:50:45 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src) : std::stack<T>(src)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &rhs)
{
    std::stack<T>::operator=(rhs);
    return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
    return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator
MutantStack<T>::rbegin(void) const
{
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend(void) const
{
    return (this->c.rend());
}
