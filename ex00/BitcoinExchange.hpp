/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:10:32 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/18 20:40:58 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<map>
#include<fstream>
#include <sstream>


class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
        std::string nameFile;
    public:
        BitcoinExchange(std::string& nameFile);
        ~BitcoinExchange();
        std::string getFile(std::string name);
        void loadBitcoinDatabase();
};

