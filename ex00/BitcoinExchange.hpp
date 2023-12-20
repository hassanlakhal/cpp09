/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:32 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/21 00:15:31 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<map>
#include<fstream>
#include <sstream>


class BitcoinExchange
{
    private:
        std::multimap<std::string, double> data;
        std::string nameFile;
    public:
        BitcoinExchange(const std::string& nameFile);
        ~BitcoinExchange();
        std::string getFile(std::string name);
        void loadBitcoinDatabase();
        void processInputLine();
};

