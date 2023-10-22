/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:57:50 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/22 12:25:15 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeSign;
        const int           _gradeExec;
    public:
        Form();                                 // default constr
        Form(std::string name, int gradeSign, int gradeExec); // param constr
        Form(const Form& instance);             // copy constr
        Form& operator=(const Form& instance);  // copy assign oper
        ~Form();                                // destructor
        
        //   getters   //
        std::string getName();
        bool        getIsSigned();
        int         getSignGrade();
        int         getExecGrade();

        void        checkGrade(int gradeSign, int gradeExec);
        void        beSigned(Bureaucrat& bur);
        
        //   exceptions   //
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

std::ostream& operator<<(std::ostream& o, Form& form);

#endif
