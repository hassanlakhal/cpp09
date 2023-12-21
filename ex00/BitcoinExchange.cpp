/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:26 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/21 07:02:00 by hlakhal-         ###   ########.fr       */
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
            double result = std::strtod(value.c_str(), NULL);
            // std::cout << result << "\t" << key << std::endl;
            data.insert(std::pair<std::string, double>(key,result));
        }
        else
            data.insert(std::pair<std::string, double>(key,-1));
    }
    // std::multimap<std::string, double>::iterator it;
    // it = data.begin();
    // while (it != data.end())
    // {
    //     std::cout << it->first << "\t" << it->second << std::endl;
    //     it++;
    // }
    
}

int BitcoinExchange::stringToInt(const char *str)
{
    char *endPtr;
    long res = strtol(str,&endPtr,10);
    if (endPtr[0] && endPtr[0] != '\n')
        return 0;
    if (res > INT_MAX || res < INT_MIN)
        return 0;
    return static_cast<int>(res);
}

void BitcoinExchange::checkFormDate(const std::string& date)
{
    std::string year , month ,day;
    int dateForm[3];
    for (size_t i = 0; i < date.length(); i++)
    {
        if (date[i] == '-')
        { 
            if(i + 2 <  date.length() && date[i + 2] == '-')
            {
                // std::cout << i << "\t"<< date << std::endl;
                switch (i)
                {
                    case 4:
                        year = date.substr(0,i);
                        month = date.substr(i + 1,1);
                        day = date.substr(i + 3,(date.length() - 1) - i);
                        break; 
                    default:
                        break;
                }
            }
            else
            { 
                switch (i)
                {
                    case 4:
                        year = date.substr(0,i);
                        month = date.substr(i + 1,2);
                        break;
                    case 7:
                        day = date.substr(i + 1,(date.length() - 1) - i);
                        break; 
                    default:
                        break;
                }
            }
            i++;
        }
        i++;
    }
    dateForm[0] = stringToInt(year.c_str());
    dateForm[1] = stringToInt(month.c_str());
    dateForm[2] = stringToInt(day.c_str());
    for (size_t i = 0; i < 3; i++)
    {
        // std::cout << i << "\t"<< dateForm[i] << std::endl;
        switch (i)
        {
            
            case 0:
                if (dateForm[i] < 2009)
                {
                    std::cout << "Error : bad input => " << date <<  std::endl;
                    return ;
                }
                break;
            case 1:
                if ((dateForm[i] < 1 || dateForm[i] > 12))
                {
                    std::cout << "Error : bad input => " << date <<  std::endl;
                    return ;
                }
                break;
            case 2:
                if (dateForm[1] == 2)
                {
                    bool leap_year = ((dateForm[0] % 4 == 0 && dateForm[0] % 100 != 0) || dateForm[0] % 400 == 0);
                    if(leap_year && (dateForm[i] < 1 || dateForm[i] > 29))
                    {
                         std::cout << "Error: Bad input for day in leap year =>" << date <<  std::endl;
                         return ;
                    }
                    else if (!leap_year && (dateForm[i] < 1 || dateForm[i] > 28))
                    {
                        std::cout << "Error: Bad input for day in non-leap year => " << date <<  std::endl;
                         return ;
                    }
                }
                else if ((dateForm[i] < 1 || dateForm[i] > 31) )
                {
                    std::cout << "Error : bad input => " << date <<  std::endl;
                    return ;
                }
                break;
            default:
                break;
        }
    }
}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t begin = str.find_first_not_of(" ");
    if (begin == std::string::npos)
        return str;
    size_t end =  str.find_last_not_of(" ");
    return str.substr(begin, end - begin + 1);
}

void BitcoinExchange::processInputLine()
{
    std::multimap<std::string, double>::iterator it;
    it = data.begin();
    while (it != data.end())
    {
        std::string date = trim(it->first);
        checkFormDate(date);
        it++;
    }
}
BitcoinExchange::~BitcoinExchange()
{
}