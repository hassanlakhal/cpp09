/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:33 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/12/30 23:45:52 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include<iostream>
#include<vector>
#include <fstream>
#include <sstream>

class PmergeMe
{
    private:
        std::vector<int> mergeMe , smallest , largest;
    public:
        PmergeMe();
        PmergeMe(std::string& strArg);
        void loadContainer(std::string& strArg);
        void makePair();
        const std::vector<int>& getVector() const;
        ~PmergeMe();
};

#endif