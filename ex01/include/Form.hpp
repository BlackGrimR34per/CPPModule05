/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:44:43 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/07 17:56:25 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form
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
		Form(void);
		Form(std::string name);
		Form(std::string name, unsigned int signGrade, unsigned int execGrade);
		~Form(void);
		Form(const Form &other);
		Form			&operator=(const Form &other);
		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getExecGrade(void) const;
		unsigned int	getSignGrade(void) const;
		void			beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif