#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(string name, int sign_grade, int exec_grade):
_name(name), _sign_grade(sign_grade), _exec_grade(exec_grade),
_signature(false) {
    validate_grade(sign_grade, BLUE + string(__PRETTY_FUNCTION__) + RESET);
    validate_grade(exec_grade, BLUE + string(__PRETTY_FUNCTION__) + RESET);
}

AForm::AForm(AForm& copy):
_name(copy.getName()), _sign_grade(copy.getSignGrade()),
_exec_grade(copy.getExecGrade()), _signature(copy.getSignature()),
target_(copy.target_) {

}

AForm& AForm::operator=(AForm& assgn) {
    _signature = assgn.getSignature();
    target_ = assgn.target_;
    return *this;
}

AForm::~AForm() {
}

const string& AForm::getName() const { return _name; }
int AForm::getSignGrade() { return _sign_grade; }
int AForm::getExecGrade() { return _exec_grade; }
bool AForm::getSignature() const { return _signature; }

void AForm::beSigned(Bureaucrat &bro) {
    if (bro.getGrade() > _sign_grade)
        throw (AForm::GradeTooLowException(string(BLUE + string(__PRETTY_FUNCTION__) + RESET)));
    _signature = 1;
}

void AForm::validate_exec(Bureaucrat const & executor) const {
    if (!getSignature())
        throw NoSignException();
    if (_exec_grade < executor.getGrade())
        throw GradeTooLowException(string(BLUE + string(__PRETTY_FUNCTION__) + RESET));
}

void AForm::validate_grade(int grade, string err) {
    if (grade < 1)
        throw AForm::GradeTooHighException(err);
    else if (grade > 150)
        throw AForm::GradeTooLowException(err);
}

ostream& operator<<(ostream &os, AForm& form) {
    return (
        os << "name: " << form.getName() << ", "
            << "sign_grade: " << form.getSignGrade() << ", "
            << "exec_grade: " << form.getExecGrade() << ", "
            << "signature: " << form.getSignature()
    );
}