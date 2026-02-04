/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:04:24 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/04 13:52:59 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
	private:
		const std::string	name;
		unsigned int		grade;

	public:
		class GradeTooHighException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(unsigned int grade);
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &other);
		std::string		getName(void) const;
		unsigned int	getGrade(void) const;
		void			decrementGrade(void);
		void			incrementGrade(void);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif