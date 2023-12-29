# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 15:10:38 by hlakhal-          #+#    #+#              #
#    Updated: 2023/12/29 12:47:30 by hlakhal-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

SRC = main.cpp BitcoinExchange.cpp
CXXFLAGS = -Wall -Wextra -Werror

CXX = c++ -std=c++98 

all:$(NAME)

OBJ = $(SRC:.cpp=.o)


$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ) 
	
fclean:clean
	rm -rf $(NAME) 

rmfiles:
	rm -rf $(OBJ)
	
re: fclean all