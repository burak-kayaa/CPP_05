#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default")
{
	std::cout << "Bureaucrat default constructor" << std::endl;
	_grade = 150;
}

Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	std::cout << "Bureaucrat constructor with grade" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor with name and grade" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : _name(bureaucrat._name)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	std::cout << "Bureaucrat assignment operator" << std::endl;
	_grade = bureaucrat._grade;
	return *this;
}

std::string const Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	std::cout << "Incrementing grade of " << getName() << std::endl;
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Decrementing grade of " << getName() << std::endl;
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void	Bureaucrat::signForm(AForm &form)
{
	if (form.getGradeToSign() < _grade)
	{
		std::cout << _name << " cannot sign " << form.getName() << " because his grade is too low" << std::endl;
	}
	else
	{
		std::cout << _name << " signs " << form.getName() << std::endl;
		form.beSigned(*this);
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	if (form.getGradeToExecute() < _grade)
	{
		std::cout << _name << " cannot execute " << form.getName() << " because his grade is too low" << std::endl;
	}
	else
	{
		std::cout << _name << " executes " << form.getName() << std::endl;
		form.execute(*this);
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}

// std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
// {
// 	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
// 	return out;
// }