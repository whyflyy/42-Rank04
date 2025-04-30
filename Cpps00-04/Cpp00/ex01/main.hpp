#ifndef MAIN_H
# define MAIN_H

# include <iostream>
# include <string>
# include <iomanip>
# include <ctime>
# include <limits>
# include "phonebook.hpp"
# include "contact.hpp"

# define RESET		"\033[0m"
# define RED		"\033[38;5;160m"
# define GREEN		"\033[38;5;76m"
# define BLUE		"\033[38;5;111m"
# define YELLOW		"\033[38;5;220m"
# define MAGENTA	"\033[38;5;183m"
# define CYAN    	"\033[38;5;87m"

# define RESET_BG	"\033[0m"
# define RED_BG		"\033[48;5;160m"
# define GREEN_BG	"\033[48;5;76m"
# define BLUE_BG	"\033[48;5;111m"
# define YELLOW_BG	"\033[48;5;221m"
# define MAGENTA_BG	"\033[48;5;183m"
# define CYAN_BG	"\033[48;5;87m"

void	ft_add_contact(Phonebook *Phonebook);
void    search_contact(Phonebook *Phonebook);

#endif
