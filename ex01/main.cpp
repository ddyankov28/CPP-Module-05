/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:54:57 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/22 13:14:13 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bur("Deyan", 16);LINE
        Form       form("Payment",17, 20);LINE
        std::cout << form << std::endl;LINE
        bur.signForm(form);LINE
        std::cout << form << std::endl;LINE

    }
    catch(std::exception& e)
    {
        std::cerr << URED << e.what() << RESET <<  std::endl;
    }
    return 0;
}
