/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:16:36 by yosherau          #+#    #+#             */
/*   Updated: 2026/02/10 17:16:36 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "../include/AForm.hpp"
# include <string>

class PresidentialPardonForm: public AForm
{
	private:
		std::string	target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		void					executeAction(void) const;
};

#endif