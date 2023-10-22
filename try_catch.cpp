/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_catch.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:59:41 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/12 13:03:14 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <iostream>

int main()
{
    int i = 20;
    
    try
    {
        i++;
        if (i != 22)
        {
            throw(std::exception());
        }
        else
            i++;
    }
    catch (std::exception wrong_num)
    {
        std::cout << "False calculations" << std::endl;
    }
    std::cout << i << std::endl;
    return 0;
}
