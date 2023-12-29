/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:35 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/29 12:46:57 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

int main(int ac, char *av[])
{    
    if (ac == 2)
    {
        BitcoinExchange obj("data.csv",',');
        obj.loadBitcoinDatabase();
        std::string inputString(av[1]);
        obj.processInputLine(inputString);
        // std::cout <<  obj.getFile() << std::endl; 
    }
    else
        std::cerr << "Error: could not open file." << std::endl;
    return 0; 
}