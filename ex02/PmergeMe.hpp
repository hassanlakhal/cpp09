/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:33 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/02 02:04:03 by hlakhal-         ###   ########.fr       */
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
#include <ctime>

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
    return pairs;
}

template<typename Container>
Container merge(const Container& left, const Container& right)
{
    Container result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            result.push_back(left[i]);
            ++i;
        }
        else
        {
            result.push_back(right[j]);
            ++j;
        }
    }
    while (i < left.size())
    {
        result.push_back(left[i]);
        ++i;
    }
    while (j < right.size())
    {
        result.push_back(right[j]);
        ++j;
    }
    return result;
}

template<typename Container>
Container recursiveSort(const Container& container)
{
    if (container.size() <= 1)
        return container;
    size_t middle = container.size() / 2;
    Container left(container.begin(), container.begin() + middle);
    Container right(container.begin() + middle, container.end());
    left = recursiveSort(left);
    right = recursiveSort(right);
    return merge(left, right);
}

template<typename Container>
void insertion(Container& sortedArr, int element)
{
    typename Container::iterator it = std::lower_bound(sortedArr.begin(), sortedArr.end(), element);
    sortedArr.insert(it, element);
}

template<typename Container>
Container fordJohnson(const Container& arr)
{
    Container mainChainLeft;
    std::vector<std::pair<int, int> > pairs = makePairs(arr);
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChainLeft.push_back(pairs[i].first);
    }
    Container mainChainRight = recursiveSort(mainChainLeft);
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        insertion(mainChainRight, pairs[i].second);
    }
    return mainChainRight;
}

#endif
