/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:52:10 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/26 15:16:29 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define SEPARATOR "\033[38;5;208m\n==============================\n\033[0m"

void wait_for_enter() {
	std::cout << "\nPress ENTER to continue..." << std::endl;
	std::cin.ignore();
	std::cout << "\033[2J\033[H"; // Clear screen
}

int	main(void)
{
	//Teste para checkar que e Abstrata
	//Animal a;

	std::cout << SEPARATOR << "Consctructors" << SEPARATOR << std::endl;
	
	int	size = 10;
	int	i = 0;
	Animal	*animals[size];

	for (i = 0; i < (size / 2); i++)
	{
		std::cout << SEPARATOR << i + 1 << std::endl;
		animals[i] = new Dog();
	}
	for (i = (size / 2); i < size; i++)
	{
		std::cout << SEPARATOR << i + 1 << std::endl;
		animals[i] = new Cat();
	}
	
	wait_for_enter();
	
	std::cout << SEPARATOR << "Animal Noises" << SEPARATOR << std::endl;

	for (i = 0; i < size; i++)
		animals[i]->makeSound();
		
	wait_for_enter();
	
	std::cout << SEPARATOR << "Check Animal Types" << SEPARATOR << std::endl;
	
	for (int i = 0; i < size; i++) //type
		std::cout << MAGENTA << i + 1 << " - " << CYAN << animals[i]->getType() << RESET << ";" << std::endl;

	wait_for_enter();

	std::cout << SEPARATOR << "Array Destructors" << SEPARATOR << std::endl;

	for (i = 0; i < size; i++)
		delete animals[i];

	wait_for_enter();

	std::cout << SEPARATOR << "Separate Dogs" << SEPARATOR << std::endl;
	
	Dog	*Doge = new Dog();

	Doge->setIdeas(1, "I want the ball!");
	std::cout << std::endl << "Doge is thinking" << std::endl << std::endl;
	Doge->think(5);

	std::cout << std::endl;

	Dog *Dobby = new Dog();
	std::cout << std::endl;
	Dog	*Darth = new Dog(*Doge);
	std::cout << std::endl;
	Doge->setIdeas(2, "Woof Woof aWOOOOOOOOOO!");
	
	*Dobby = *Doge;

	std::cout << std::endl << "Dobby is thinking" << std::endl << std::endl;
	Dobby->think(5);
	std::cout << std::endl << "Darth is thinking" << std::endl << std::endl;
	Darth->think(5);
	std::cout << std::endl;
	
	delete Doge;
	delete Dobby;
	delete Darth;

	wait_for_enter();

	std::cout << SEPARATOR << "Separate Cats" << SEPARATOR << std::endl;
	
	Cat	*Kittie = new Cat();

	Kittie->setIdeas(1, "I want to sleep!");
	std::cout << std::endl << "Kittie is thinking" << std::endl << std::endl;
	Kittie->think(5);

	std::cout << std::endl;

	Cat *Garfield = new Cat();
	std::cout << std::endl;
	Cat	*Catniss = new Cat(*Kittie);
	std::cout << std::endl;
	Kittie->setIdeas(2, "Gimme the Lasagna!");
	
	*Garfield = *Kittie;

	std::cout << std::endl << "Garfield is thinking" << std::endl << std::endl;
	Garfield->think(5);
	std::cout << std::endl << "Catniss is thinking" << std::endl << std::endl;
	Catniss->think(5);
	std::cout << std::endl;
	
	delete Kittie;
	delete Garfield;
	delete Catniss;
}