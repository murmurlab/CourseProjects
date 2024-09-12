#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(AForm& dup) :
AForm(dup) {

}

PresidentialPardonForm::PresidentialPardonForm(string target) :
AForm((string(__FILE__)).erase(string(__FILE__).size() - 4), 25, 5) {
    target_ = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    validate_exec(executor);
    cout<< "Inform that " << target_ << " has been pardoned by Zaphod Beeblebrox." <<endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(AForm& assign) {
    AForm::operator=(assign);
    return *this;
}