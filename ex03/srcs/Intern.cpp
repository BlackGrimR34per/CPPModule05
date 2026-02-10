/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:10:50 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/10 19:46:51 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

# define NUM_OF_FORM 3

Intern::Intern(void)
{
	std::cout << "Intern's default constructor was called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern is no longer an intern" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern's copy constructor was called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern's copy assignment operator was called " << std::endl;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string	formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	AForm *(*creator[3])(const std::string &target) = {
		&createPresidential,
		&createRobotomy,
		&createShrubbery
	};
	
	for (size_t index = 0; index < name.length(); index++)
		name[index] = static_cast<char>(std::tolower(static_cast<unsigned char>(name[index])));
	for (int index = 0; index < NUM_OF_FORM; index++)
		if (formNames[index] == name)
		{
			std::cout << "Intern creates " << formNames[index] << std::endl;
			return (creator[index](target));
		}
	std::cout << "Form name does not exist" << std::endl;
	return (NULL);
}

AForm	*createPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}
AForm	*createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}