/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:54:28 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/23 17:09:02 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << GREEN << "Bureaucrat Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    checkGrade(grade);
    _grade = grade;
    std::cout << GREEN << "Bureaucrat Param constructor called" << RESET << std::endl;
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

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
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
    return "Grade is Too High";
}

const char*    Bureaucrat::GradeTooLowException::what()const throw()
{
    return "Grade is Too Low";   
}

void    Bureaucrat::checkGrade(int grade) const
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();     
}

void    Bureaucrat::signAForm(AForm& AForm)
{
    try
    {
        AForm.beSigned(*this);
        std::cout << "Bureaucrat called " << getName() << " signed";
        std::cout << " a AForm called " << AForm.getName() << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cerr  << URED << "Bureaucrat called " << getName() << " couldn't";
        std::cerr << " sign a AForm called " << AForm.getName() << " because\n";
        std::cerr << e.what() << RESET << std::endl;
    }
           
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& instance)
{
    o << instance.getName() << ", Bureaucrat grade is " << instance.getGrade();
    return o;
}

void    Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << "Bureaucrat called " << getName() << " executed";
        std::cout << " a form " << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << URED << "Bureaucrat called " << getName() << " couldn't";
        std::cerr << " execute a form" << " because\n" << e.what() << RESET << std::endl;
    }
}
