/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:04:22 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/07 18:14:05 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

Bureaucrat::Bureaucrat(void):
	name("Who this"), grade(150)
{
	std::cout << "Bureaucrat's default constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name):
name(name), grade(150)
{
	std::cout << "Bureaucrat's parameterised constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(unsigned int grade):
	name("Who this"), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat's parameterised constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade):
	name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat's parameterised constructor was called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat has mysteriously disappeared :0" << std::endl;
}

// Must figure out the inner working's of this line
Bureaucrat::Bureaucrat(const Bureaucrat &other):
	name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat's copy constructor was called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.grade;
	std::cout << "Bureaucrat's copy assignment operator was called" << std::endl;
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade(void)
{
	// this->grade = (--grade < 1) ? throw GradeTooHighException() : grade;
	--grade;
	if (grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade(void)
{
	// this->grade = (++grade > 150) ? throw GradeTooLowException() : grade;
	++grade;
	if (grade > 150)
		throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because bureacrat's grade was not high enough" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}