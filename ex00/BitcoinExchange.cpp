/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:26 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/18 20:46:43 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"
            
BitcoinExchange::BitcoinExchange(std::string& nameFile) : nameFile(nameFile)
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

void BitcoinExchange::loadBitcoinDatabase()
{
    
    std::string dataBase = this->getFile(this->nameFile);
    std::istringstream my_file(dataBase);
    std::string temp;
    float key;
    std::string value;
    while(std::getline(my_file,temp,"|"))
    {
        std::istringstream pairStream(temp);
        float key;
        std::string value;
        std::getline();
    }
}

BitcoinExchange::~BitcoinExchange()
{
}