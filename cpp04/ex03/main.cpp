/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:09:04 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    std::cout << "=== CREATE MATERIA SOURCE ===" << std::endl;
    IMateriaSource *src = new MateriaSource();
    std::cout << std::endl;

    std::cout << "=== LEARN NEW MATERIAS ===" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    std::cout << std::endl;

    std::cout << "=== TRY TO LEARN WITH NO SLOTS LEFT ===" << std::endl;
    Ice *ice_tmp = new Ice();
    Cure *cure_tmp = new Cure();
    src->learnMateria(ice_tmp);
    src->learnMateria(cure_tmp);
    std::cout << std::endl;

    std::cout << "=== CREATE 'ME' CHARACTER ===" << std::endl;
    ICharacter *me = new Character("me");
    std::cout << std::endl;

    std::cout << "=== EQUIP MATERIAS IN 'ME' CHARACTER ===" << std::endl;
    AMateria *tmp;
    AMateria *extra;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    std::cout << std::endl;

    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    std::cout << std::endl;

    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;

    std::cout << "=== TRY TO EQUIP WITH NO SLOTS LEFT ===" << std::endl;
    extra = src->createMateria("ice");
    me->equip(extra);
    std::cout << std::endl;

    std::cout << "=== TRY TO CREATE UNKNOWN MATERIA ===" << std::endl;
    AMateria *fail;
    fail = src->createMateria("fire");
    (void)fail;
    std::cout << std::endl;

    std::cout << "=== UNEQUIP 'ME'S LAST SLOT ===" << std::endl;
    me->unequip(3);
    std::cout << std::endl;

    std::cout << "=== TRY TO UNEQUIP 'ME'S INVALID SLOTS ===" << std::endl;
    me->unequip(3);
    me->unequip(4);
    std::cout << std::endl;

    std::cout << "=== CREATE 'BOB' CHARACTER ===" << std::endl;
    ICharacter *bob = new Character("bob");
    std::cout << std::endl;

    std::cout << "=== USE 'ME'S MATERIA IN 'BOB' ===" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << std::endl;

    std::cout << "=== TRY TO USE INVALID SLOTS IN 'BOB' ===" << std::endl;
    bob->use(3, *me);
    bob->use(4, *me);
    std::cout << std::endl;

    std::cout << "=== CHECK CHARACTER CTOR COPY ===" << std::endl;
    Character jim("jim");

    jim.equip(src->createMateria("ice"));
    jim.equip(src->createMateria("cure"));
    std::cout << std::endl;

    Character tim(jim);
    std::cout << std::endl;

    std::cout << "=== CHECK CHARACTER ASSIGN COPY ===" << std::endl;
    Character jon("jon");

    jon.equip(src->createMateria("ice"));
    jon.equip(src->createMateria("cure"));
    std::cout << std::endl;

    Character tom;
    tom = jon;
    std::cout << std::endl;

    std::cout << "=== CHECK MATERIA SOURCE CTOR COPY ===" << std::endl;
    MateriaSource ms;

    ms.learnMateria(new Ice());
    ms.learnMateria(new Cure());
    std::cout << std::endl;

    MateriaSource msCopy(ms);
    std::cout << std::endl;

    std::cout << "=== CHECK MATERIA SOURCE ASSIGN COPY ===" << std::endl;
    MateriaSource ms2;

    ms2.learnMateria(new Ice());
    ms2.learnMateria(new Cure());
    std::cout << std::endl;

    MateriaSource msAssign;
    msAssign = ms2;
    std::cout << std::endl;

    std::cout << "=== DESTROY BOB ===" << std::endl;
    delete bob;
    std::cout << std::endl;

    std::cout << "=== DESTROY ME ===" << std::endl;
    delete me;
    std::cout << std::endl;

    std::cout << "=== DESTROY MATERIA SOURCE ===" << std::endl;
    delete src;
    std::cout << std::endl;

    std::cout << "=== DESTROY AUXILIARY VARIABLES ===" << std::endl;
    delete ice_tmp;
    delete cure_tmp;
    delete tmp;
    delete extra;

    return (0);
}
