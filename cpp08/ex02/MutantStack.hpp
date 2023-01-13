/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:41:34 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/12 23:50:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef typename std::stack<T>::container_type::iterator
            iterator;
        typedef typename std::stack<T>::container_type::const_iterator
            const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator
            reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator
            const_reverse_iterator;

        MutantStack(void);
        MutantStack(MutantStack const &src);
        ~MutantStack(void);

        MutantStack<T> &operator=(MutantStack<T> const &src);

        iterator               begin(void);
        iterator               end(void);
        const_iterator         begin(void) const;
        const_iterator         end(void) const;
        reverse_iterator       rbegin(void);
        reverse_iterator       rend(void);
        const_reverse_iterator rbegin(void) const;
        const_reverse_iterator rend(void) const;
};

#include "MutantStack.tpp"

#endif /* MUTANT_STACK_HPP */
