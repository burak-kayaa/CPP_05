#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	if (this == &assign)
		return (*this);
	AForm::operator=(assign);
	_target = assign._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream outfile ((executor.getName() + "_shrubbery").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}
	outfile << "      /\\      " << std::endl;
	outfile << "     /\\*\\     " << std::endl;
	outfile << "    /\\O\\*\\    " << std::endl;
	outfile << "   /*/\\/\\/\\   " << std::endl;
	outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
	outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	outfile << "      ||      " << std::endl;
	outfile <<      "      ||      " << std::endl;
	outfile <<      "      ||      " << std::endl;
	outfile << "      ||      " << std::endl;
	outfile << "      ||      " << std::endl;
	outfile << "      ||      " << std::endl;
	outfile << "     /||\\     " << std::endl;
	outfile << "    / || \\    " << std::endl;
	outfile << "   /  ||  \\ " << std::endl;
	outfile.close();

	std::cout << "ShrubberyCreationForm has been executed by " << executor.getName() << std::endl;
}

