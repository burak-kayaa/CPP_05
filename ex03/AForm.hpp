#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		AForm();
		AForm(const int gradeToSign, const int gradeToExecute);
		AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &assign);

	public:
		// Orthodox Canon Classes
		// Member Functions
		~AForm();
		const std::string	&getName() const;
		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor) const;
		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, AForm *Aform);

#endif