/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:19:18 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/10 17:15:57 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PresedentialForm", 25, 5), target("Random Person")
{
	std::cout << "PresidentialPardonForm's default constructor was called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresedentialForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm's default constructor was called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm was unpardoned" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm(other), target(other.target)
{
	std::cout << "PresidentialPardonForm's copy constructor was called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "PresidentialPardonForm's copy assignment operator was called" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::executeAction(void) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}