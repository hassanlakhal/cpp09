/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:36 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/01 23:13:03 by hlakhal-         ###   ########.fr       */
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
        vect1 = fordJohnson(vect);
        std::vector<int>::iterator it = vect1.begin();
        while (it != vect1.end() - 1)
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout <<"\n";
        std::cout << "----------\n";
        que = fordJohnson(que);
        std::deque<int>::iterator it1 =  que.begin();
        while (it1 !=  que.end() - 1)
        {
            std::cout << *it1 << " ";
            it1++;
        }
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << '\n';
    }
}