#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try {
        Bureaucrat sonmezx("Sonmez", 1);
        Bureaucrat ekox("Eko", 1);
        // Bureaucrat paulx("Paul", 151);
        // Bureaucrat bot1("Bot1", 0);
        // Bureaucrat bot2("Bot2", -12);
        std::cout << "\033[1;33m--------------------------------------------------------\033[0m" << std::endl;
        std::cout << sonmezx.getName() << " - " << sonmezx.getGrade() << std::endl;
        // ekox.incrementGrade();
        sonmezx.decrementGrade();
        RobotomyRequestForm temp("Temp");
        ekox.executeForm(temp);
        std::cout << ekox << std::endl;

        std::cout << "\033[1;31m----- SHRUBBERY FORM -----\033[0m" << std::endl;
        ShrubberyCreationForm a("formA");
        std::cout << a << std::endl;
        a.execute(sonmezx);
        sonmezx.signForm(a);
        a.execute(sonmezx);
        std::cout << a.isSigned() << std::endl;

        std::cout << "\033[1;32m----- ROBOTOMY FORM -----\033[0m" << std::endl;
        RobotomyRequestForm b("formB");
        std::cout << b << std::endl;
        sonmezx.signForm(b);
        b.execute(sonmezx);

        std::cout << "\033[1;34m----- PRESIDENTIAL PARDON FORM -----\033[0m" << std::endl;
        PresidentialPardonForm c("formC");
        std::cout << c << std::endl;
        sonmezx.signForm(c);
        c.execute(sonmezx);
        std::cout << "\033[1;33m--------------------------------------------------------\033[0m" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}