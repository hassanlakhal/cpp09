/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:44 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/01 01:14:00 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

template <typename randomAccess>
void merge(randomAccess first, randomAccess middle, randomAccess last)
{
    typedef typename std::iterator_traits<randomAccess>::value_type randomIt;
    std::vector<randomIt> temp(first, last);
    randomAccess left = temp.begin();
    randomAccess right = temp.begin() + (middle - first);
    randomAccess merged = first;

    while (left < temp.begin() + (middle - first) && right < temp.end()) 
    {
        if (*left < *right) 
            *merged++ = *left++;
        else 
            *merged++ = *right++;
    }
    while (left < temp.begin() + (middle - first)) 
        *merged++ = *left++;
    while (right < temp.end())
        *merged++ = *right++;
}

template <typename RandomAccess>
void mergeSort(RandomAccess& mergeMe, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(mergeMe, left,mid);
        mergeSort(mergeMe, mid + 1,right);
        merge(mergeMe.begin() + left, mergeMe.begin() + mid + 1, mergeMe.begin() + right + 1);
    }
}

template <typename randomAccess>
void insertSort(randomAccess& S, randomAccess L)
{
    
    typename randomAccess::iterator it = L.begin();
    while (it != L.end())
    {
       ++it;
        typename randomAccess::iterator ind = std::lower_bound(S.begin(),S.end(),*it);
        S.insert(ind, *it);
    }
}

void PmergeMe::makePair()
{
    std::vector<std::pair<int,int> > pairs;
    std::vector<int>::iterator it = mergeMe.begin();
    size_t cont =  mergeMe.size() % 2 != 0 ? mergeMe.size() - 1 : mergeMe.size();
    std::cout << "first : ( " << cont << " )" << std::endl;
    for (size_t i = 0; i < cont; i += 2)
    {
        if (it[i] < it[i + 1])
            std::swap(it[i],it[i + 1]);
        pairs.push_back(std::pair<int, int>(it[i], it[i + 1]));
        std::cout << "first : ( " << pairs[i].first << " )" << std::endl;
    }
    // for (size_t i = 0; i < pairs.size(); i++)
    // {
    //     largest.push_back(pairs[i].first);
    //     smallest.push_back(pairs[i].second);
    // }
    if (mergeMe.size() % 2 != 0)
        smallest.push_back(it[cont]);
    // mergeSort(smallest, 0, smallest.size() - 1);
    // insertSort(smallest,largest);
    // std::vector<int>::iterator it1 = smallest.begin();
    size_t i = 0;
    while (i < pairs.size())
    {
        std::cout << "first : ( " << pairs[i].first << " )" << std::endl;
        std::cout << "last : ( " << pairs[i].second << " )" << std::endl;
        // std::cout << it1[i] << std::endl;
        i++;
    }
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

PmergeMe::PmergeMe(PmergeMe& other)
{
    this->smallest = other.smallest;
    this->largest = other.largest;
    this->mergeMe = other.mergeMe;
}

PmergeMe& PmergeMe::operator=(PmergeMe& other)
{
    if (this != &other)
    {
        this->smallest = other.smallest;
        this->largest = other.largest;
        this->mergeMe = other.mergeMe;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
    
}