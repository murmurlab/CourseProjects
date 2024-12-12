#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(string name, int grade): 
_name(name), _grade(grade) {
    validate_grade(grade, BLUE + string(__PRETTY_FUNCTION__) + RESET);
}

Bureaucrat::Bureaucrat(Bureaucrat &copy):
_name(copy._name), _grade(copy._grade) {

}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &assignment) {
    _grade = assignment._grade;
    return *this;
}

const string& Bureaucrat::getName() { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::gradeUp(int value){
    validate_grade(_grade - value, BLUE + string(__PRETTY_FUNCTION__) + RESET);
    _grade -= value;
}

void Bureaucrat::gradeDown(int value){
    validate_grade(_grade + value, BLUE + string(__PRETTY_FUNCTION__) + RESET);
    _grade += value;
}

ostream& operator<<(ostream& os, Bureaucrat& bro) {
    return (
        os << bro.getName()
            << ", bureaucrat grade "
            << bro.getGrade()
    );
}

void Bureaucrat::executeForm(AForm const & form) const try {
    form.execute(*this);
    cout<< _name << " executed " << form.getName() <<endl;
} catch (exception& e) {
    cout<< e.what() <<endl;
}

void Bureaucrat::signForm(AForm& form) try {
    form.beSigned(*this);
    cout << this->getName() << " signed " << form.getName() << endl;
} catch (exception& e) {
    cout << this->_name << " couldn’t sign " << form.getName() << " because "
        << e.what() << "." << endl;
}

void Bureaucrat::validate_grade(int grade, string err) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException(err);
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException(err);
}