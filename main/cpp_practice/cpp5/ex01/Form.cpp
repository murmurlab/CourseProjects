#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(string name, int sign_grade, int exec_grade):
    _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signature(false) {
    if (sign_grade < 1 || exec_grade < 1) {
        throw Form::GradeTooHighException();
    } else if (sign_grade > 150 || exec_grade > 150) {
        throw (Form::GradeTooLowException());
    }
}

Form::Form(Form& copy):
    _name(copy.getName()), _sign_grade(copy.getSignGrade()),
    _exec_grade(copy.getExecGrade()), _signature(copy.getSignature()) {}

//operator=
Form& Form::operator=(Form& assgn){
    _signature = assgn.getSignature();
    return *this;
}

Form::~Form()
{
}

const string& Form::getName() { return _name; }
int Form::getSignGrade() { return _sign_grade; }
int Form::getExecGrade() { return _exec_grade; }
bool Form::getSignature() { return _signature; }

void Form::beSigned(Bureaucrat &bro){
    if (bro.getGrade() <= _sign_grade)
        _signature = 1;
    else {
        throw (Form::GradeTooLowException());
    }
}


ostream& operator<<(ostream &os, Form& form){
    return (
        os << "name: " << form.getName() << ", "
            << "sign_grade: " << form.getSignGrade() << ", "
            << "exec_grade: " << form.getExecGrade() << ", "
            << "signature: " << form.getSignature()
    );
}
