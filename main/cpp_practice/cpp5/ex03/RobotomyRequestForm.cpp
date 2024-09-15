#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(AForm& dup) :
AForm(dup) {

}

RobotomyRequestForm::RobotomyRequestForm(string target) :
AForm((string(__FILE__)).erase(string(__FILE__).size() - 4), 72, 45) {
    target_ = target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    validate_exec(executor);
    std::srand(std::time(NULL));
    cout<< "...Making some drilling noises now..." <<endl;
    if (rand() % 2)
        cout << "Informing that " << target_ << " has been robotomized successfully" << endl;
    else
        cout << "Informing that the robotomy failed" << endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(AForm& assign) {
    AForm::operator=(assign);
    return *this;
}