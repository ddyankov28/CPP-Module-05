/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:57:50 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/25 16:41:04 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeSign;
        const int           _gradeExec;
    public:
        AForm();                                 // default constr
        AForm(std::string name, int gradeSign, int gradeExec); // param constr
        AForm(const AForm& instance);             // copy constr
        AForm& operator=(const AForm& instance);  // copy assign oper
        virtual ~AForm();                                // destructor
        
        //   getters   //
        std::string getName();
        bool        getIsSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        void        checkGrade(int gradeSign, int gradeExec);
        void        beSigned(const Bureaucrat& bur);
        virtual void        execute(Bureaucrat const & executor) const = 0;
        
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

std::ostream& operator<<(std::ostream& o, AForm& AForm);

#endif
