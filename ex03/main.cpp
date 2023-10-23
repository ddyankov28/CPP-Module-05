/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:54:57 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/23 15:52:32 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

int main()
{
    Intern i;LINE
    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* nothing;

    rrf = i.makeForm("robotomy request", "Bender");LINE
    scf = i.makeForm("shrubbery creation", "Shrubb");LINE
    ppf = i.makeForm("presidential pardon", "Pardon");LINE
    nothing = i.makeForm("nothing" ,"Nothing");LINE
    
    delete rrf;LINE
    delete scf;LINE
    delete ppf;LINE
    
    return 0;
}
