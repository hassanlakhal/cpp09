/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:35 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/18 16:53:07 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

int main(int ac, char *av[])
{    
    if (ac == 2)
    {
        BitcoinExchange obj;
        std::cout <<  obj.getFile(av[1]) << std::endl; 
    }
    else
        std::cerr << "Error: could not open file." << std::endl;
    return 0; 
}