/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:54:55 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/10 17:16:13 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubForm", 145, 137), target("home")
{
	std::cout << "ShrubberyCreationForm's default constructor was called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm's parameterised constructor was called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm was uprooted" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm's copy constructor was called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "ShrubberyCreationForm's copy assignment operator was called" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	outFile(target + "_shrubbery");
	std::ifstream	inputFile("art.txt");

	if (!outFile.is_open())
		std::exit(EXIT_FAILURE);
	std::string	line;
	while (std::getline(inputFile, line))
		outFile << line << std::endl;
	inputFile.close();
	outFile.close();
}