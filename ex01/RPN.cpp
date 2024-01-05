/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:39:19 by hlakhal-          #+#    #+#             */
/*   Updated: 2024/01/05 01:28:11 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RPN.hpp"

RPN::RPN()
{
    
}

RPN::~RPN()
{

}

void RPN::splitString(const std::string& strToken) 
{
    std::istringstream stream(strToken);
    std::string token;
    while (std::getline(stream, token, ' ')) 
        tokens.push_back(token);
}

int RPN::performOperation(int number1, int number2, char op) 
{
    switch (op) 
    {
        case '+':
            return number1 + number2;
        case '-':
            return number1 - number2;
        case '*':
            return number1 * number2;
        case '/':
            if (number2 == 0)
                throw std::runtime_error("Division by zero");
            return number1 / number2;
        default:
            throw std::invalid_argument("Invalid operator");
    }
}

void RPN::evaluateRPN(std::string& strArg)
{
    std::string operationsToken = "+-/*";
    splitString(strArg);
    std::list<std::string>::iterator it = tokens.begin();
    while (it != tokens.end())
    {
        std::string number(*it);
        if (number.length() == 1 && isdigit(number[0]))
        {
            int digit = atoi(number.c_str());
            rpnList.push(digit);
        }
        else if (number.length() == 1 && std::find(std::begin(operationsToken),std::end(operationsToken),number[0]) != std::end(operationsToken))
        {
            if (rpnList.size() < 2)
                throw std::runtime_error(" Error :size of stack !! ");
            int number1 = rpnList.top();
            rpnList.pop();
            int number2 = rpnList.top();
            rpnList.pop();
            int result =  performOperation(number2,number1,number[0]);
            rpnList.push(result);
        }
        else
            throw std::invalid_argument(" Error ");
        it++;
    }
    std::cout << rpnList.top() << std::endl;
}