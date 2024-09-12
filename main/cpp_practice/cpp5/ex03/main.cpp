#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) try {
    // Bureaucrat bro("some_bureaucrat", -135 + 137);
    // ShrubberyCreationForm form("home");
    // RobotomyRequestForm form2("school");
    // PresidentialPardonForm form42("ahbasara");
    // bro.signForm(form);
    // bro.signForm(form42);
    // cout<< form2.getSignature() << " - " << form2.target_ <<endl;
    // form2 = form;
    // cout<< form2.getSignature() << " - " << form2.target_ <<endl;
    // ShrubberyCreationForm form3(form2);
    // cout<< form3.getSignature() << " - " << form3.target_ <<endl;
    // // form.execute(bro); // do not run directly
    // bro.executeForm(form2);
    // bro.executeForm(form42);
    // cout << form42 << endl;
    // Bureaucrat bro1("an_unnamed_bureaucrat_75", 75);
    // Bureaucrat bro2("a_named_bureaucrat_42", 42);
    // cout << "=====================================================" << endl;
    // cout << "bro2: " << bro2.getGrade() << " " << bro2.getName() << endl;
    // cout << "bro1: " << bro1.getGrade() << " " << bro1.getName() << endl;
    // Bureaucrat copy(bro2);
    // cout << "copy(bro2): " << copy.getGrade() << " " << copy.getName() << endl;
    // bro1 = bro2;
    // cout << "bro1 = bro2: " << bro1.getGrade() << " " << bro1.getName() << endl;
    // try {
    //     bro1.gradeDown(150);
    //     cout << "graded" << endl;
    //     bro1.gradeUp(150);
    //     cout << "graded" << endl;
    // } catch (exception & e) {
    //     cout << e.what() << endl;
    // }
    // cout << bro1 << endl;
    // return 0;
    {
        Bureaucrat bro("some_bureaucrat", -136 + 137);

        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
        bro.signForm(*rrf);
        cout<< *rrf <<endl;
        bro.executeForm(*rrf);
    }
} catch (exception& e) {
    cout<< e.what() << " catched from main! " <<endl;
}
