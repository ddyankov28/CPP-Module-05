/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:54:57 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/23 14:39:52 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
    try
    {   
        Bureaucrat bur("Deyan", 2);LINE

        ShrubberyCreationForm   form("ascii_tree");LINE
        bur.signAForm(form);LINE
        std::cout << form << std::endl;LINE
        bur.executeForm(form);LINE

        RobotomyRequestsForm robot("Robot");
        bur.signAForm(robot);LINE
        std::cout << robot << std::endl;LINE
        bur.executeForm(robot);LINE

        PresidentialPardonForm pardon("Pardon");LINE
        bur.signAForm(pardon);LINE
        std::cout << pardon << std::endl;LINE
        bur.executeForm(pardon);LINE
    }
    catch (std::exception& e)
    {
        std::cerr << URED << e.what() << RESET << std::endl;
    }
    return 0;
}
