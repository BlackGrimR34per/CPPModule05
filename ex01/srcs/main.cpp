/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:20:06 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/07 18:20:30 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Bureaucrat.hpp"
# include "../include/Form.hpp"

int	main(void)
{
	std::cout << "=== CONSTRUCTOR TESTS ===" << std::endl;

	try {
		Form f1("Normal", 50, 25);
		std::cout << f1 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f2("TopBoundary", 1, 1);
		std::cout << f2 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f3("BottomBoundary", 150, 150);
		std::cout << f3 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== CONSTRUCTOR EXCEPTION TESTS ===" << std::endl;

	try {
		Form f("TooHighSign", 0, 50);
	} catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try {
		Form f("TooHighExec", 50, 0);
	} catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try {
		Form f("TooLowSign", 151, 50);
	} catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try {
		Form f("TooLowExec", 50, 151);
	} catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== SIGNING TESTS ===" << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Manager", 50);
	Bureaucrat intern("Intern", 150);

	Form contract("Contract", 75, 50);
	std::cout << contract << std::endl;

	// Fail case
	intern.signForm(contract);
	std::cout << contract << std::endl;

	// Success case
	boss.signForm(contract);
	std::cout << contract << std::endl;

	std::cout << "\n=== DOUBLE SIGN TEST ===" << std::endl;

	Form permit("Permit", 50, 20);
	boss.signForm(permit);
	boss.signForm(permit);  // Should not crash
	std::cout << permit << std::endl;
}