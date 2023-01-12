/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:14:40 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/11 23:03:53 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
    std::cout << "Array has been created via default constructor\n";
}

template <typename T>
Array<T>::Array(size_t n) : _array(NULL), _size(n)
{
    if (n > 0)
        this->_array = new T[n];
    std::cout << "Array has been created via parametric constructor\n";
}

template <typename T>
Array<T>::Array(Array const &src) : _array(NULL), _size(src._size)
{
    if (src._size > 0) {
        this->_array = new T[src._size];
        for (size_t i = 0; i < src._size; ++i)
            this->_array[i] = src._array[i];
    }
    std::cout << "Array has been created via copy constructor\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::~Array(void)
{
    if (this->_array)
        delete[] this->_array;
    std::cout << "Array has been destroyed\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
    if (this->_array)
        delete[] this->_array;
    this->_array = NULL;
    if (rhs._array) {
        this->_array = new T[rhs._size];
        for (size_t i = 0; i < rhs._size; ++i)
            this->_array[i] = rhs._array[i];
    }
    this->_size = rhs._size;
    std::cout << "Array assignment operator has been called\n";
    return (*this);
}

template <typename T>
T &Array<T>::operator[](size_t i)
{
    if (i >= this->_size)
        throw std::out_of_range("Exception: Index out of range");
    return (this->_array[i]);
}

template <typename T>
T const &Array<T>::operator[](size_t i) const
{
    if (i >= this->_size)
        throw std::out_of_range("Exception: Index out of range");
    return (this->_array[i]);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

template <typename T>
size_t Array<T>::size(void) const
{
    return (this->_size);
}
