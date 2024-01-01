/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:33 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/01 01:07:27 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include<iostream>
#include<vector>
#include <fstream>
#include <sstream>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> mergeMe , smallest , largest;
    public:
        PmergeMe();
        PmergeMe(std::string& strArg);
        PmergeMe(PmergeMe& other);
        PmergeMe& operator=(PmergeMe& other);
        void loadContainer(std::string& strArg);
        void makePair();
        const std::vector<int>& getVector() const;
        ~PmergeMe();
};

#endif