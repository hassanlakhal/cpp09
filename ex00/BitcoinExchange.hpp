/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:32 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/21 23:53:20 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <cstdlib>


class BitcoinExchange
{
    private:
        std::multimap<std::string, double> data;
        std::string nameFile;
        char c;
    public:
        BitcoinExchange(const std::string& nameFile, char c);
        ~BitcoinExchange();
        std::string getFile(std::string name);
        void loadBitcoinDatabase();
        void checkFormDate(const std::string& date);
        int stringToInt(const char* str);
        std::string trim(const std::string& str);
        void processInputLine();
};

