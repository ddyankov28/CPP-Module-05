/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:16:20 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/23 13:30:54 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTOMYREQUESTSFORM_HPP
# define ROBOTOMYREQUESTSFORM_HPP

# include "AForm.hpp"

class RobotomyRequestsForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestsForm(std::string target);
        RobotomyRequestsForm(const RobotomyRequestsForm& inst);
        RobotomyRequestsForm& operator=(const RobotomyRequestsForm& inst);
        ~RobotomyRequestsForm();

        //getter
        std::string    getTarget() const;

        void    execute(Bureaucrat const & executor) const;  
};

# endif
