/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:54:28 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/22 12:55:18 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << GREEN << "Bureaucrat Default constuctor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    checkGrade(grade);
    _grade = grade;
    std::cout << GREEN << "Bureaucrat Param constuctor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& instance)
{
    *this = instance;
    std::cout << YELLOW << "Bureaucrat Copy constructor called" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& instance)
{
    _grade = instance._grade;
    std::cout << CYAN << "Bureaucrat Copy assignment operator called" << RESET <<  std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << RED << "Bureaucrat Destructor called" << RESET << std::endl;
}

std::string Bureaucrat::getName()
{
    return _name;
}

int Bureaucrat::getGrade()
{
    return _grade;
}

void    Bureaucrat::incrementGrade()
{
    if (_grade - 1 != 0)
        _grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void    Bureaucrat::decrementGrade()
{
    if (_grade + 1 != 151)
        _grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}

const char*    Bureaucrat::GradeTooHighException::what()const throw()
{
    return "Bureaucrat Grade is Too High";
}

const char*    Bureaucrat::GradeTooLowException::what()const throw()
{
    return "Bureaucrat Grade is Too Low";   
}

void    Bureaucrat::checkGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();     
}

void    Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "Bureaucrat called " << getName() << " signed";
        std::cout << " a form called " << form.getName() << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cerr  << URED << "Bureaucrat called " << getName() << " couldn't";
        std::cerr << " sign a form called " << form.getName() << " because\n";
        std::cerr << e.what() << RESET << std::endl;
    }
           
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& instance)
{
    o << instance.getName() << ", Bureaucrat grade is " << instance.getGrade();
    return o;
}
