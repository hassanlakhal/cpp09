/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:36 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/02 16:01:31 by hlakhal-         ###   ########.fr       */
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
        display(vect,"Before: ");
        vect1 = fordJohnson(vect);
        display(vect1,"After:  ");
        clock_t endTime = clock();
        double elapsedTime = static_cast<double>(endTime - startTime)  / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << vect.size() ;
        std::cout << " elements with std::vector : " << std::fixed << elapsedTime  << " s" << std::endl;
        startTime = clock();
        que = fordJohnson(que);
        endTime = clock();
        elapsedTime = static_cast<double>(endTime - startTime)  / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " <<  que.size() ;
        std::cout << " elements with std::deque : " << std::fixed << elapsedTime  << " s" << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << '\n';
    }
}