/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:44 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/01 16:22:25 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

// PmergeMe::PmergeMe()
// {
    
// }

// void PmergeMe::operator()(std::string& input) 
// {
//     PmergeMe a(input);
// }


// template<typename T>
// void PmergeMe::loadContainer(T strArg)
// {
//     std::istringstream ss(strArg);
//     for (size_t i = 0; i < strArg.size(); i++)
//     {
//         if (!isdigit(strArg[i]) && !iswspace(strArg[i]))
//             throw std::runtime_error("Error : invalid argment !!");
//     }
// }

// template<typename containerSort>
// containerSort& loadContainer(std::string& strArg, containerSort& sortA)
// {
//     std::istringstream ss(strArg);
//     std::string number;
//     long nb = 0;
//     while (std::getline(ss, number,' '))
//     {
//         loadContainer(number);
//         std::istringstream nbr(number);
//         nbr >> nb;
//         if (nb > INT32_MAX || nb < 0)
//         {
//             if (sortA.size() != 0)
//                 sortA.clear();
//             throw std::runtime_error("Error : out of rang !!");
//         }
//         sortA.push_back(static_cast<int>(nb));
//     }
// }
