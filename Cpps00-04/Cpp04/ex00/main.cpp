/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:59:02 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/26 10:25:12 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	//Testes do subject
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "This animal is: " << j->getType() << " " << std::endl;
	std::cout << "This animal is: " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n";
	std::cout << GREEN << "--- Wrong Animal ---" << RESET << "\n";
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "This animal is: " << wrong->getType() << "\n";
	std::cout << "This animal is: " << wrongCat->getType() << "\n";
	wrongCat->makeSound();
	wrong->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrongCat;
	
	return (0);
}

