# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 17:03:46 by jcavadas          #+#    #+#              #
#    Updated: 2025/03/02 17:03:46 by jcavadas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++
C++FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = main.cpp phonebook.cpp contact.cpp utils.cpp

OBJS = $(SRC:.cpp=.o)

NAME = phonebook

all: $(NAME)

#TODO fazer print de mensagens ao fazer make ao inves de mostrar files;

$(NAME):$(OBJS)
	$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: