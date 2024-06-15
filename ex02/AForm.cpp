#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const int gradeToSign, const int gradeToExecute) : _name("default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &assign)
{
	if (this == &assign)
		return (*this);
	_signed = assign._signed;
	return (*this);
}

const std::string &AForm::getName() const { return (_name); }

bool AForm::isSigned() const { return (_signed); }

int AForm::getGradeToSign() const { return (_gradeToSign); }

int AForm::getGradeToExecute() const { return (_gradeToExecute); }

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() { return ("Grade is too high"); }

const char *AForm::GradeTooLowException::what() const throw() { return ("Grade is too low"); }

const char *AForm::FormNotSignedException::what() const throw() { return ("Form is not signed"); }

void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	if (!_signed)
		throw AForm::FormNotSignedException();
}

std::ostream	&operator<<(std::ostream &o, AForm *Aform)
{
	o << "AForm: " << Aform->getName() << ", Grade to Sign: " << Aform->getGradeToSign() << ", Grade to Execute: " << Aform->getGradeToExecute() << ", Signed: " << Aform->isSigned() << std::endl;
	return (o);
}


