/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:44 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/30 21:52:03 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

void PmergeMe::loadContainer(std::string& strArg)
{
    std::istringstream ss(strArg);
    for (size_t i = 0; i < strArg.size(); i++)
    {
        if (!isdigit(strArg[i]) && !iswspace(strArg[i]))
            throw std::runtime_error("Error : invalid argment !!");
        else if (isdigit(strArg[i]))
            i++;
    }
}

PmergeMe::PmergeMe(std::string& strArg)
{
    std::istringstream ss(strArg);
    std::string number;
    long nb = 0;
    while (std::getline(ss, number,' '))
    {
        loadContainer(number);
        std::istringstream nbr(number);
        nbr >> nb;
        if (nb > INT32_MAX || nb < 0)
        {
            if (mergeMe.size() != 0)
                mergeMe.clear();
            throw std::runtime_error("Error : out of rang !!");
        }
        mergeMe.push_back(static_cast<int>(nb));
    }
}

PmergeMe::~PmergeMe()
{
    
}