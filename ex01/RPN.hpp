/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:39:03 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/05 05:34:57 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<stack>
#include <list>
#include <sstream>
#include <cctype> 
#include <stdexcept> 

class RPN
{
    private:
        std::stack<int> rpnList;
        std::list<std::string> tokens;
    public:
        RPN();
        ~RPN();
        void evaluateRPN(std::string& strArg);
        void splitString(const std::string& strToken);
        int performOperation(int operand1, int operand2, char op);
};
