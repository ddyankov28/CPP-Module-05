/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:26:05 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/25 16:40:56 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExec(100)
{
    std::cout << GREEN << "AForm Default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    checkGrade(gradeSign, gradeExec);
    std::cout << GREEN << "AForm Param constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm& instance) : _name(instance._name), _isSigned(false), _gradeSign(instance._gradeSign), _gradeExec(instance._gradeExec)
{
    std::cout << YELLOW << "AForm Copy constructor called" << RESET << std::endl; 
}

AForm& AForm::operator=(const AForm&)
{
    std::cout << CYAN << "AForm Copy assignment operator called" << RESET <<  std::endl;
    return *this;
}

AForm::~AForm()
{
    std::cout << RED << "AForm Destructor called" << RESET << std::endl;
}

const char*    AForm::GradeTooLowException::what()const throw()
{
    return "Grade is Too Low";   
}

const char*    AForm::GradeTooHighException::what()const throw()
{
    return "Grade is Too High";   
}

void    AForm::checkGrade(int gradeSign, int gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
}

void    AForm::beSigned(const Bureaucrat& bur)
{
    if (bur.getGrade() <= _gradeSign)
        _isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

std::string AForm::getName()
{
    return _name;
}

bool    AForm::getIsSigned() const
{
    return _isSigned;
}

int   AForm::getSignGrade() const
{
    return _gradeSign;
}

int   AForm::getExecGrade() const
{
    return _gradeExec;
}

std::ostream& operator<<(std::ostream& o, AForm& AForm)
{
    o << "AForm with the name " << AForm.getName() << std::endl;
    o << "requires a grade of minimum " << AForm.getSignGrade() << " to be signed" << std::endl;
    o << "requires a grade of minimum " << AForm.getExecGrade() << " to be executed" << std::endl;
    if (AForm.getIsSigned())
        o << "and is already signed";
    else
        o << "and is not signed yet";
    return o;
}

void    AForm::execute(Bureaucrat const & executor) const
{
    (void)executor;
}
