/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:33 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/01 23:09:53 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <utility>
#include <iterator>

template<typename T>
void loadContainer(T strArg)
{
    std::istringstream ss(strArg);
    for (size_t i = 0; i < strArg.size(); i++)
    {
        if (!isdigit(strArg[i]) && !iswspace(strArg[i]))
            throw std::runtime_error("Error: Invalid argument!!");
    }
}

template<typename Container>
void loadContainer(std::string& strArg, Container& sortA)
{
    std::istringstream ss(strArg);
    std::string number;
    long nb = 0;
    while (std::getline(ss, number, ' '))
    {
        loadContainer(number);
        std::istringstream nbr(number);
        nbr >> nb;
        if (nb > INT32_MAX || nb < 0)
        {
            if (sortA.size() != 0)
                sortA.clear();
            throw std::runtime_error("Error: Out of range!!");
        }
        sortA.push_back(static_cast<int>(nb));
    }
}

template<typename Container>
std::vector<std::pair<int, int> > makePairs(const Container& arr)
{
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size())
            pairs.push_back(std::make_pair(std::min(arr[i], arr[i + 1]), std::max(arr[i], arr[i + 1])));
        else
            pairs.push_back(std::make_pair(arr[i], arr[i]));
    }
    sort(pairs.begin(), pairs.end());
    return pairs;
}

template<typename Container>
Container recursiveSort(const std::vector<std::pair<int, int> >& pairs)
{
    Container mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        mainChain.push_back(pairs[i].second);
    }
    if (mainChain.size() > 1)
    {
        std::vector<std::pair<int, int> > newPairs = makePairs(mainChain);
        return recursiveSort<Container>(newPairs);
    }
    else
        return mainChain;
}

template<typename Container>
void insertion(Container& sortedArr, int element)
{
    typename Container::iterator it = lower_bound(sortedArr.begin(), sortedArr.end(), element);
    sortedArr.insert(it, element);
}

template<typename Container>
Container fordJohnson(const Container& arr)
{
    std::vector<std::pair<int, int> > pairs = makePairs(arr);
    Container mainChain = recursiveSort<Container>(pairs);
    for (size_t i = 0; i < arr.size(); ++i)
    {
        insertion(mainChain, arr[i]);
    }
    return mainChain;
}

#endif
