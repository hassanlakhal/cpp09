/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:26 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/21 03:22:11 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"
            
BitcoinExchange::BitcoinExchange(const std::string& nameFile, char c) : nameFile(nameFile), c(c) 
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
    std::ifstream file(this->nameFile.c_str());
    if (!file.is_open()) 
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream pairStream(line);
        std::string key, value;
        if (std::getline(pairStream, key, this->c) && std::getline(pairStream, value))
        {
            if (!key.empty() && !value.empty())
            {
                double result = std::strtod(value.c_str(), NULL);
                data.insert(std::pair<std::string, double>(key,result));
            }
            else
                std::cout << "error empty" << std::endl;
        }
    }
    // std::multimap<std::string, double>::iterator it;
    // it = data.begin();
    // while (it != data.end())
    // {
    //     std::cout << it->first << "\t" << it->second << std::endl;
    //     it++;
    // }
    
}

void BitcoinExchange::checkFormDate(const std::string& date)
{
    std::string year , month ,day;
    static int cont;
    for (size_t i = 0; i < date.length(); i++)
    {
        if (date[i] == '-')
        {
            switch (i)
            {
                case 4:
                    year = date.substr(0,i);
                    month = date.substr(i + 1,2);
                    break;
                case 7:
                    day = date.substr(i + 1,2);
                    break; 
                default:
                    break;
            }
            i++;
        }
        i++;
    }
    std::cout << "date : " << year << "\t" << month << "\t" << day << std::endl;
}

void BitcoinExchange::processInputLine()
{
    std::multimap<std::string, double>::iterator it;
    it = data.begin();
    while (it != data.end())
    {
        checkFormDate(it->first);
        // std::cout << it->first << "\t" << it->second << std::endl;
        it++;
    }
}
BitcoinExchange::~BitcoinExchange()
{
}