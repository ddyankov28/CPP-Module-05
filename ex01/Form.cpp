/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:26:05 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/23 17:04:57 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExec(100)
{
    std::cout << GREEN << "Form Default constructor called" << RESET << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    checkGrade(gradeSign, gradeExec);
    std::cout << GREEN << "Form Param constructor called" << RESET << std::endl;
}

Form::Form(const Form& instance) : _name(instance._name), _isSigned(false), _gradeSign(instance._gradeSign), _gradeExec(instance._gradeExec)
{
    std::cout << YELLOW << "Form Copy constructor called" << RESET << std::endl; 
}

Form& Form::operator=(const Form&)
{
    std::cout << CYAN << "Form Copy assignment operator called" << RESET <<  std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << RED << "Form Destructor called" << RESET << std::endl;
}

const char*    Form::GradeTooLowException::what()const throw()
{
    return "Grade is Too Low";   
}

const char*    Form::GradeTooHighException::what()const throw()
{
    return "Grade is Too High";   
}

void    Form::checkGrade(int gradeSign, int gradeExec) const
{
    if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
}

void    Form::beSigned(Bureaucrat& bur)
{
    if (bur.getGrade() <= _gradeSign)
        _isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::string Form::getName() const
{
    return _name;
}

bool    Form::getIsSigned() const
{
    return _isSigned;
}

int   Form::getSignGrade() const
{
    return _gradeSign;
}

int   Form::getExecGrade() const
{
    return _gradeExec;
}

std::ostream& operator<<(std::ostream& o, Form& form)
{
    o << "Form with the name " << form.getName() << std::endl;
    o << "requires a grade of minimum " << form.getSignGrade() << " to be signed" << std::endl;
    o << "requires a grade of minimum " << form.getExecGrade() << " to be executed" << std::endl;
    if (form.getIsSigned())
        o << "and is already signed";
    else
        o << "and is not signed yet";
    return o;
}
