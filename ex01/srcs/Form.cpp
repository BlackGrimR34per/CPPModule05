/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:07:58 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/07 18:17:51 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(void):
	name("Default Form"), isSigned(false), signGrade(150), execGrade(150)
{
	std::cout << "Default Form constructor was called" << std::endl;
}

Form::Form(std::string name):
	name(name), isSigned(false), signGrade(150), execGrade(150)
{
	std::cout << "Form's parameterised constructor was called" << std::endl;
}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade):
	name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form's parameterised constructor was called" << std::endl;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form had too high of a grade");	
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form had too low of a grade");	
}

Form::~Form()
{
	std::cout << "Forms destructor was called" << std::endl;
}

Form::Form(const Form &other):
	name(other.name), execGrade(other.execGrade), signGrade(other.signGrade), isSigned(other.isSigned)
{
	std::cout << "Forms copy constructor was called" << std::endl;
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "Forms copy assignment operator was called" << std::endl;
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::getIsSigned(void) const
{
	return (this->isSigned);
}

unsigned int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

unsigned int Form::getExecGrade(void) const
{
	return (this->execGrade);
}

void		Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	std::cout << form.getName() << ", form's sign grade " << form.getSignGrade() << ", form's exec grade " << form.getExecGrade() << std::endl;
	return (out);
}