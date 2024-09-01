#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(string name, int grade): 
    _name(name) {
    if (grade < 1) {
        GradeTooHighException e;
        throw e;
    } else if (grade > 150) {
        GradeTooLowException e;
        throw(e);
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &copy):
    _name(copy._name), _grade(copy._grade) {}

const string& Bureaucrat::getName() { return _name; }

int Bureaucrat::getGrade() { return _grade; }

void Bureaucrat::gradeUp(int value){
    if (_grade - value < 1) {
        GradeTooHighException e;
        throw e;
    } else
        _grade -= value;
}

void Bureaucrat::gradeDown(int value){
    if (_grade + value > 150) {
        GradeTooLowException e;
        throw(e);
    } else 
        _grade += value;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &assignment) {
    _grade = assignment._grade;
    return *this;
}

ostream& operator<<(ostream& os, Bureaucrat& bro) {
    return (
        os <<
        bro.getName() <<
        ", bureaucrat grade " <<
        bro.getGrade()
    );
}
