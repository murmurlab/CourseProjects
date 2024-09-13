# include "Intern.hpp"

AForm* ctor_ShrubberyCreationForm(string target) {
    return (new ShrubberyCreationForm(target));
}

AForm* ctor_RobotomyRequestForm(string target) {
    return (new RobotomyRequestForm(target));
}

AForm* ctor_PresidentialPardonForm(string target) {
    return (new PresidentialPardonForm(target));
}

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(string form_name, string target_of_form) {
    for (size_t i = 0; i < FORM_COUNT; i++) {
        if (form_names[i] == form_name) {
            return (form_constructors[i](target_of_form));
        }
    }
    return nullptr;
}

const string Intern::form_names[FORM_COUNT] = {
    "ShrubberyCreationForm",
    "RobotomyRequestForm",
    "PresidentialPardonForm"
};

AForm* (*Intern::form_constructors[FORM_COUNT])(string)  = {
    &ctor_ShrubberyCreationForm,
    &ctor_RobotomyRequestForm,
    &ctor_PresidentialPardonForm,
};