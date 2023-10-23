/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:44:53 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/23 17:14:17 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{
    std::cout << GREEN << "Intern constructor called" << RESET << std::endl;
}

Intern::~Intern()
{
    std::cout << RED << "Intern destructor called" << RESET << std::endl;
}

Intern::Intern(const Intern& inst)
{
    *this = inst;
    std::cout << YELLOW << "Presidental copy constructor called" << RESET << std::endl; 
}

Intern& Intern::operator=(const Intern& inst)
{
    (void)inst;
    std::cout << CYAN << "Presidental Copy assignment operator called" << RESET <<  std::endl;
    return *this;
}

AForm*  Intern::makeForm(std::string formName, std::string target) const
{
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    int i = 0;
    int name = 3;
    
    while (i < 3)
    {
        if (formName == names[i])
        {
            name = i;
            break ;
        }
        i++;
    }
    
    switch (name)
    {
        case 0: return new ShrubberyCreationForm(target);
        case 1: return new RobotomyRequestsForm(target);
        case 2: return new PresidentialPardonForm(target);
            break ;
        default:
            std::cout << URED << "This kind of Form does not exist" << RESET << std::endl;
    }
    return NULL;
}
