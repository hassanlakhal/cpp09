/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:25:36 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/01 01:23:46 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PmergeMe.hpp"

int main(int ac, char *ag[])
{
  try
  {
    if (ac >= 2)
    {
      for (int i = 1; i < ac; i++)
      {
          std::string input(ag[i]);
          PmergeMe a(input); 
          
      } 
      a.makePair();
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
}