/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:55:46 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/10 17:16:08 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RobotomyForm", 72, 45), target("Random Peepo")
{
	std::cout << "RobotomyCreationForm's default constructor was called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyForm", 72, 45), target(target)
{
	std::cout << "RobotomyCreationForm's parameterised constructor was called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm was unrobotised" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm(other), target(other.target)
{
	std::cout << "RobotomyRequestForm's copy constructor was called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "RobotomyRequestForm's copy assignment operator was called" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::executeAction(void) const
{
	std::cout << "Makes some drilling noises" << std::endl;
	std::random_device	rd;
	std::mt19937 mt_eng(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	int outcome = dist(mt_eng);
	if (outcome == 0)
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy has failed 🥀" << std::endl;
}