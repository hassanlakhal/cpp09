/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:26 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/18 17:22:07 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"
            
BitcoinExchange::BitcoinExchange(/* args */)
{
}

std::string BitcoinExchange::getFile(std::string name)
{
    std::ifstream fileData;
    fileData.open(name);
    std::string data ,line; 
    while (std::getline(fileData,line))
    {
        data.append(line + "\n");
    }
    return data;   
}

void BitcoinExchange::dataFile()

BitcoinExchange::~BitcoinExchange()
{
}