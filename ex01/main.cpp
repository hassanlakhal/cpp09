/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:05:28 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/29 17:55:28 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

int main(int ac, char *av[])
{
    try
    {
        if (ac == 2)
        {
            RPN a;
            std::string input(av[1]);
            if (input.empty())
                throw std::runtime_error("Error : empty argument");
            a.evaluateRPN(input);
        }
        else
            throw std::runtime_error("Error : invalid arguments");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}