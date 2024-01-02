/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:36 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/02 01:54:47 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

int main(int ac, char* ag[]) 
{
    std::vector<int> vect;
    std::vector<int> vect1;
    std::deque<int> que;
    try 
    {
        
        if (ac >= 2) 
        {
            for (int i = 1; i < ac; i++) 
            {
                std::string input(ag[i]);
                loadContainer(input, vect);
                loadContainer(input, que);
            }
        }
        clock_t startTime = clock();
        vect1 = fordJohnson(vect);
        std::vector<int>::iterator it = vect1.begin();
        while (it != vect1.end())
        {
            std::cout << *it << " ";
            it++;
        } 
        std::cout <<"\n";
        clock_t endTime = clock();
        double elapsedTime = static_cast<double>(endTime - startTime) * 1e6 / CLOCKS_PER_SEC;
        std::cout << "time : "<< elapsedTime  << " s" << std::endl;
        std::cout << "----------\n";
        startTime = clock();
        que = fordJohnson(que);
        std::deque<int>::iterator it1 =  que.begin();
        while (it1 !=  que.end())
        {
            std::cout << *it1 << " ";
            it1++;
        }
        std::cout <<"\n";
        endTime = clock();
        elapsedTime = static_cast<double>(endTime - startTime) * 1e6 / CLOCKS_PER_SEC;
        std::cout << "time : "<< elapsedTime  << " s" << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << '\n';
    }
}