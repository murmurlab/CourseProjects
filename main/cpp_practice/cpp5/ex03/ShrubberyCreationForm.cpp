#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(AForm& dup) :
AForm(dup) {

}

ShrubberyCreationForm::ShrubberyCreationForm(string target) :
AForm((string(__FILE__)).erase(string(__FILE__).size() - 4), 145, 137) {
    target_ = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    validate_exec(executor);
    ofstream file((target_ + "_shrubbery").c_str());
    file.exceptions(ofstream::failbit | ofstream::badbit);
    file << ASCII_TREE;
    file.close();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(AForm& assign) {
    AForm::operator=(assign);
    return *this;
}