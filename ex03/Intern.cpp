#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &ref)
{
	*this = ref;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &ref)
{
	(void)ref;
	return (*this);
}

static AForm	*createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}
AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm	*(*forms[])(std::string target) = {
		createShrubberyCreationForm,
		createRobotomyRequestForm,
		createPresidentialPardonForm
	};
	std::string	formNames[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	AForm *form = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			form = forms[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << "Intern cannot create " << formName << " form" << std::endl;
	return (NULL);
}

