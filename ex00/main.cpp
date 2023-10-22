/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:06:08 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/22 13:02:30 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main()
{
    Bureaucrat First; LINE
    Bureaucrat Second("Deyan", 1); LINE
    First.incrementGrade();
    std::cout << "First Name is: " << First.getName() << std::endl;
    std::cout << "First Grade is: " << First.getGrade() << std::endl;LINE
    std::cout << "Second Name is: " << Second.getName() << std::endl;
    std::cout << "Second Grade is: " << Second.getGrade() << std::endl;LINE
    try
    {
        Bureaucrat Third("Emily", 151);LINE
    }
    catch(std::exception& e)
    {
        std::cerr << URED << e.what() << RESET <<  std::endl;
    }LINE
    try
    {
        Bureaucrat Fourth("Gabi", 1);LINE
        Fourth.incrementGrade();LINE
    }
    catch(std::exception& e)
    {
        std::cerr << URED << e.what() << RESET <<  std::endl;
    }LINE
    try
    {
        Bureaucrat Fifth("Viki", 150);LINE
        Fifth.decrementGrade();LINE
    }
    catch(std::exception& e)
    {
        std::cerr << URED << e.what() << RESET <<  std::endl;
    }LINE
    try
    {
        Bureaucrat Sixth("Zori", 100);LINE
        std::cout << Sixth << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << URED << e.what() << RESET <<  std::endl;
    }LINE
    Bureaucrat a;
    std::cout << a << std::endl;
    return 0;
}
