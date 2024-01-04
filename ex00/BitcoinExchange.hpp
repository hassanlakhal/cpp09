/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:32 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/04 19:26:48 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <cstdlib>
#include <cmath>


class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
        std::string nameFile;
    public:
        BitcoinExchange(const std::string& nameFile);
        ~BitcoinExchange();
        std::string getFile(std::string& name);
        void loadBitcoinDatabase();
        bool checkFormDate(const std::string& date);
        int stringToInt(const char* str);
        std::string trim(const std::string& str);
        void processInputLine(std::string& nameFile);
        void checkExchangeRate(std::string& value, std::string& key);
        double getExchangeRate(std::string& strDate) const;
};

