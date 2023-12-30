/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:44 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/30 23:44:22 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

void PmergeMe::makePair()
{
    std::vector<std::pair<int,int> > pairs;
    std::vector<int>::iterator it = mergeMe.begin();
    size_t cont =  mergeMe.size() % 2 != 0 ? mergeMe.size() - 1 : mergeMe.size();
    for (size_t i = 0; i < cont; i += 2)
    {
        if (it[i] < it[i + 1])
            std::swap(it[i],it[i + 1]);
        pairs.push_back(std::pair<int, int>(it[i], it[i + 1]));
    }
    for (size_t i = 0; i < pairs.size(); i++)
    {
        smallest.push_back(pairs[i].first);
        largest.push_back(pairs[i].second);
    }
    if (mergeMe.size() % 2 != 0)
        smallest.push_back(it[cont]);
    // for (const std::pair<int, int>& pair : pairs) 
    // {
    //     std::cout << "(" << pair.first << ", " << pair.second << ")\n";
    // }
}

void PmergeMe::loadContainer(std::string& strArg)
{
    std::istringstream ss(strArg);
    for (size_t i = 0; i < strArg.size(); i++)
    {
        if (!isdigit(strArg[i]) && !iswspace(strArg[i]))
            throw std::runtime_error("Error : invalid argment !!");
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