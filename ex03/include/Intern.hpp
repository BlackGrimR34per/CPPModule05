/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:00:14 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/10 19:15:43 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "./AForm.hpp"

class Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		AForm	*makeForm(std::string name, std::string target);
};

AForm	*createPresidential(const std::string &target);
AForm	*createRobotomy(const std::string &target);
AForm	*createShrubbery(const std::string &target);

#endif