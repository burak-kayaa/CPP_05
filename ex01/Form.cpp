#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const int gradeToSign, const int gradeToExecute) : _name("default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

Form::~Form() {}

Form &Form::operator=(const Form &assign)
{
	if (this == &assign)
		return (*this);
	_signed = assign._signed;
	return (*this);
}

const std::string &Form::getName() const { return (_name); }

bool Form::isSigned() const { return (_signed); }

int Form::getGradeToSign() const { return (_gradeToSign); }

int Form::getGradeToExecute() const { return (_gradeToExecute); }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() { return ("Grade is too high"); }

const char *Form::GradeTooLowException::what() const throw() { return ("Grade is too low"); }


std::ostream	&operator<<(std::ostream &o, Form *form)
{
	o << "Form: " << form->getName() << ", Grade to Sign: " << form->getGradeToSign() << ", Grade to Execute: " << form->getGradeToExecute() << ", Signed: " << form->isSigned() << std::endl;
	return (o);
}


