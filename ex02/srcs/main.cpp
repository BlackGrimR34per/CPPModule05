/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:40:42 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/10 17:57:55 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	baby("baby");
	Bureaucrat	executor("executor", 1);
	Bureaucrat	boss("boss", 1);

	ShrubberyCreationForm shrub;
	PresidentialPardonForm presi;
	RobotomyRequestForm robot;

	boss.signForm(shrub);
	boss.signForm(presi);
	boss.signForm(robot);

	baby.executeForm(shrub);
	baby.executeForm(presi);
	baby.executeForm(robot);

	executor.executeForm(shrub);
	executor.executeForm(presi);
	executor.executeForm(robot);
}