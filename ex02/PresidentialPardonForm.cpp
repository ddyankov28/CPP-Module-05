/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:49 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/23 15:00:48 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidental", 25, 5)
{
    if (!target.empty())
        _target = target;
    else
        _target = "default";
    std::cout << GREEN << "Presidental constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << RED << "Presidental Destructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& inst)
{
    *this = inst;
    std::cout << YELLOW << "Presidental copy constructor called" << RESET << std::endl; 
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& inst)
{
    _target = inst.getTarget();
    std::cout << CYAN << "Presidental Copy assignment operator called" << RESET <<  std::endl;
    return *this;
}

std::string    PresidentialPardonForm::getTarget() const
{
    return _target;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecGrade() || !getIsSigned())
        throw GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
