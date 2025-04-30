/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:52:43 by jcavadas          #+#    #+#             */
/*   Updated: 2025/04/30 12:17:34 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	print_args(char *arg)
{
	while (*arg != '\0')
	{
		if (std::isalpha(*arg))
			std::cout << (char)std::toupper(*arg);
		else
			std::cout << *arg;
		arg++;
	}
}

int main(int argc, char **argv)
{
	argv++;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*argv != NULL)
		{
			print_args(*argv);
			argv++;
		}
		std::cout << std::endl;
	}
	return (0);
}
