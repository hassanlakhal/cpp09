/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:26 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/29 12:48:25 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"
            
BitcoinExchange::BitcoinExchange(const std::string& nameFile, char c) : nameFile(nameFile), c(c) 
{
    
}

std::string BitcoinExchange::getFile(std::string& name)
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
            data.insert(std::pair<std::string, double>(key,result));
        }
        else
            data.insert(std::pair<std::string, double>(key,-1));
    }
}

int BitcoinExchange::stringToInt(const char *str)
{
    char *endPtr;
    long res = strtol(str,&endPtr,10);
    if (endPtr[0])
        return 0;
    return static_cast<int>(res);
}

bool BitcoinExchange::checkFormDate(const std::string& date)
{
    std::string year , month ,day;
    int dateForm[3];
    int moths[4] = {4,6,9,11};
    if (date.length() > 10)
    {
        std::cout << "Error : bad input => " << date <<  std::endl;
        return false;
    }
    std::istringstream pairStream(date);
    std::getline(pairStream,year,'-');
    std::getline(pairStream,month,'-');
    pairStream >> day;
    if (year.length() != 4 || month.length() != 2 || day.length() != 2)
    {
        std::cout << "Error : bad input => " << date <<  std::endl;
        return false;
    }
    dateForm[0] = stringToInt(year.c_str());
    dateForm[1] = stringToInt(month.c_str());
    dateForm[2] = stringToInt(day.c_str());
    for (size_t i = 0; i < 3; i++)
    {
        switch (i)
        {
            case 0:
                if (dateForm[i] < 2009)
                {
                    std::cout << "Error : bad input => " << date <<  std::endl;
                    return false;
                }
                break;
            case 1:
                if ((dateForm[i] < 1 || dateForm[i] > 12))
                {
                    std::cout << "Error : bad input => " << date <<  std::endl;
                    return false;
                }
                break;
            case 2:
                if (dateForm[1] == 2)
                {
                    bool leap_year = ((dateForm[0] % 4 == 0 && dateForm[0] % 100 != 0) || dateForm[0] % 400 == 0);
                    if(leap_year && (dateForm[i] < 1 || dateForm[i] > 29))
                    {
                         std::cout << "Error: Bad input for day in leap year =>" << date <<  std::endl;
                         return false;
                    }
                    else if (!leap_year && (dateForm[i] < 1 || dateForm[i] > 28))
                    {
                        std::cout << "Error: Bad input for day in non-leap year => " << date <<  std::endl;
                        return false;
                    }
                }
                else if ((dateForm[i] < 1 || dateForm[i] > 31))
                {
                    std::cout << "Error : bad input => " << date <<  std::endl;
                    return false;
                }
                else if (((dateForm[i] < 1 || dateForm[i] > 30)) && std::find(std::begin(moths),std::end(moths),dateForm[i - 1]) != std::end(moths))
                {
                    std::cout << "Error : bad input => " << date <<  std::endl;
                    return false;
                }
                break;
            default:
                break;
        }
    }
    return true;
}

double BitcoinExchange::getExchangeRate(std::string& strDate) const
{
    std::multimap<std::string, double>::const_iterator it = data.lower_bound(strDate);

    if (it == data.begin())
        return it->second; 
    if (it == data.end() || (it->first != strDate && it != data.begin()))
        --it;
    return it->second;
}

void BitcoinExchange::checkExchangeRate(std::string& value, std::string& key)
{
    char *endPtr;
    std::istringstream ss(value);
    long nbr;
    ss >> nbr;
    double res = strtod(value.c_str(),&endPtr);
    if (!checkFormDate(key))
        return ;
    if (*endPtr)
    {
        std::cout << "Error : bad input => " << key <<  std::endl;
        return ;
    }
    else if (nbr > 10000 || res > 10000.00)
    {
        std::cout << "Error: too large a number." << std::endl;
        return ;
    }
    else if (nbr < 0 || res < 0.0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return ;
    }
    double exchangeRate =  getExchangeRate(key);
    double result = res * exchangeRate;
    std::cout << key << " => " << res << " = " << result << std::endl;   
}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t begin = str.find_first_not_of(" ");
    if (begin == std::string::npos)
        return str;
    size_t end =  str.find_last_not_of(" ");
    return str.substr(begin, end - begin + 1);
}

void BitcoinExchange::processInputLine(std::string& nameFile)
{
    std::ifstream fileData;
    fileData.open(nameFile);
    std::string data ,line;
    while (std::getline(fileData,line))
    {
        std::istringstream pairStream(line);
        std::string key, value;
        if (std::getline(pairStream, key, '|') && std::getline(pairStream, value))
        {
            key = trim(key);
            value = trim(value);
        }
        else
        {
            key = trim(key);
            value = "none";
        }
        checkExchangeRate(value, key);
    }
}
BitcoinExchange::~BitcoinExchange()
{
}