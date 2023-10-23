/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:53:59 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/23 11:49:06 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define URED "\033[4;31m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define LINE  std::cout << "-------------------------" << std::endl;

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat();                                       // default construct
        Bureaucrat(std::string name, int grade);            // parame construct
        Bureaucrat(const Bureaucrat& instance);             // copy construct
        Bureaucrat& operator=(const Bureaucrat& instance);  // copy assignment operator
        ~Bureaucrat();                                      // destructor
        
        std::string getName() const;
        int         getGrade() const;
        
        void        incrementGrade();
        void        decrementGrade();
        void        checkGrade(int grade) const;
        void        signAForm(AForm& AForm);
        void        executeForm(AForm const & form);
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        // virtual = it can be overridden in derived classes
        // const = not allowed to modify state of object
        // throw() = cant throw any exceptions ( noexcept )
};

std::ostream& operator<<(std::ostream& o, Bureaucrat& instance);

# endif
