#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    try {
		Intern someRandomIntern;
		AForm *robotomy_form = someRandomIntern.makeForm("RobotomyRequestForm", "ekox");
		AForm *presidential_form = someRandomIntern.makeForm("PresidentialPardonForm", "paulx");
       
        std::cout << std::endl;
		Bureaucrat sonmezx("Sönmez", 23);

        std::cout << sonmezx << std::endl << std::endl;
		std::cout << "debug" <<	std::endl;
        std::cout << *robotomy_form << std::endl;
        robotomy_form->beSigned(sonmezx);
        robotomy_form->execute(sonmezx);
        std::cout << std::endl;

        std::cout << *presidential_form << std::endl;
        presidential_form->beSigned(sonmezx);
        presidential_form->execute(sonmezx);
        std::cout << std::endl;
        delete robotomy_form;
        delete presidential_form;
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}