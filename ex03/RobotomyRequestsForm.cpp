/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestsForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:51:20 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/23 15:00:24 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include <cstdlib>
# include <ctime>
# include <unistd.h>

RobotomyRequestsForm::RobotomyRequestsForm(std::string target) : AForm("Robotomy", 72, 45)
{
    if (!target.empty())
        _target = target;
    else
        _target = "default";
    std::cout << GREEN << "Robotomy constructor called" << RESET << std::endl;
}

RobotomyRequestsForm::~RobotomyRequestsForm()
{
    std::cout << RED << "Robotomy Destructor called" << RESET << std::endl;
}

RobotomyRequestsForm::RobotomyRequestsForm(const RobotomyRequestsForm& inst)
{
    *this = inst;
    std::cout << YELLOW << "Robotomy copy constructor called" << RESET << std::endl; 
}

RobotomyRequestsForm& RobotomyRequestsForm::operator=(const RobotomyRequestsForm& inst)
{
    _target = inst.getTarget();
    std::cout << CYAN << "Robotomy Copy assignment operator called" << RESET <<  std::endl;
    return *this;
}

std::string    RobotomyRequestsForm::getTarget() const
{
    return _target;
}

void    RobotomyRequestsForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecGrade() || !getIsSigned())
        throw GradeTooLowException();
    int i = 0;
    while (i < 10000)
    {
        std::cout << "\a";
        usleep(100);
        i++;
    }
    std::srand(std::time(NULL)); // use curr time as seed for random generator
    int val = std::rand() % 2 + 1;
    if (val == 1)
        std::cout << GREEN << _target << " has been robotomized successfully" << RESET <<std::endl;
    else
        std::cout << RED << "Robotomy failed" << RESET << std::endl;
}
