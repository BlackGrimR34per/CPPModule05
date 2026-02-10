/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:07:58 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/07 20:36:29 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(void):
	name("Default AForm"), signGrade(150), execGrade(150), isSigned(false)
{
	std::cout << "Default AForm constructor was called" << std::endl;
}

AForm::AForm(std::string name):
	name(name), signGrade(150), execGrade(150), isSigned(false)
{
	std::cout << "AForm's parameterised constructor was called" << std::endl;
}

AForm::AForm(std::string name, unsigned int signGrade, unsigned int execGrade):
	name(name), signGrade(signGrade), execGrade(execGrade), isSigned(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm's parameterised constructor was called" << std::endl;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm had too high of a grade");	
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm had too low of a grade");	
}

const char	*AForm::FormNotSigned::what() const throw()
{
	return ("Form was not signed :0");	
}

AForm::~AForm()
{
	std::cout << "AForms destructor was called" << std::endl;
}

AForm::AForm(const AForm &other):
	name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), isSigned(other.isSigned)
{
	std::cout << "AForms copy constructor was called" << std::endl;
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "AForms copy assignment operator was called" << std::endl;
	return (*this);
}

std::string AForm::getName(void) const
{
	return (this->name);
}

bool AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

unsigned int AForm::getSignGrade(void) const
{
	return (this->signGrade);
}

unsigned int AForm::getExecGrade(void) const
{
	return (this->execGrade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > execGrade)
		throw GradeTooLowException();
	else if (!isSigned)
		throw FormNotSigned();
	executeAction();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	std::cout << form.getName() << ", form's sign grade " << form.getSignGrade() << ", form's exec grade " << form.getExecGrade() << std::endl;
	return (out);
}