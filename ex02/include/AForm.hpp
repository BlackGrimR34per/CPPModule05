/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:44:43 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/10 17:16:40 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const unsigned int	signGrade;
		const unsigned int	execGrade;
		bool				isSigned;

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
		class FormNotSigned: public std::exception
		{
			public:
				const char	*what() const throw();
		};
		AForm(void);
		AForm(std::string name);
		AForm(std::string name, unsigned int signGrade, unsigned int execGrade);
		~AForm(void);
		AForm(const AForm &other);
		AForm			&operator=(const AForm &other);
		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getExecGrade(void) const;
		unsigned int	getSignGrade(void) const;
		void			beSigned(const Bureaucrat &bureaucrat);
		void			execute(Bureaucrat const &executor) const;
		virtual void	executeAction(void) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif