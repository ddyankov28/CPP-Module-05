/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:40:38 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/23 15:00:31 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137)
{
    if (!target.empty())
        _target = target + "_shrubbery";
    else
        _target = "default_shrubbery";
    std::cout << GREEN << "Shrubbery constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << RED << "Shrubbery Destructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& inst)
{
    *this = inst;
    std::cout << YELLOW << "Shrubbery copy constructor called" << RESET << std::endl; 
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& inst)
{
    _target = inst.getTarget();
    std::cout << CYAN << "Shrubbery Copy assignment operator called" << RESET <<  std::endl;
    return *this;
}

std::string    ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecGrade() || !getIsSigned())
        throw GradeTooLowException();
    std::ofstream   file;

    file.open(_target.c_str());
    if (file.is_open())
    {
        file << "    *    " << std::endl;
        file << "   ***   " << std::endl;
        file << "  *****  " << std::endl;
        file << " ******* " << std::endl;
        file << "*********" << std::endl;
        file.close();
    }
    else
        std::cerr << "Error creating or opening the file" << std::endl;
}
