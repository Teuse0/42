/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:30:25 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:30:26 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "------------ Animal ------------" << std::endl;

	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "dog Type: " << dog->getType() << " " << std::endl;
	std::cout << "cat Type: " << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete  meta;
	delete  dog;
	delete  cat;

	std::cout << std::endl << "---------- Wrong Animal ----------" << std::endl;

	const WrongAnimal *wrong = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "Wrong Type: " << wrong->getType() << " " << std::endl;
	std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();

	delete  wrong;
	delete  wrongCat;

	return (0);
}
