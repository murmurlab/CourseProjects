#include "Bureaucrat.hpp"

int main( void ) {
    try {
        Bureaucrat bro("an unnamed bureaucrat", 75);
        Bureaucrat bruh("a named bureaucrat", 42);
        cout << "bruh instantinated" << endl;
        cout << bro.getGrade() << endl;
        cout << bro.getName() << endl;
        Bureaucrat copy(bruh);
        cout << "copy: " << copy.getName() << ", " << copy.getGrade() << endl;
        bro = bruh;
        cout << "new grade bro: " << bro.getGrade() << endl;
        try {
            bro.gradeDown(150);
            cout << "graded" << endl;
            bro.gradeUp(150);
            cout << "graded" << endl;
        } catch (exception & e) {
            cout << e.what() << endl;
        }
        cout << bro << endl;
    } catch ( exception & e ) {
        cout << "bruh cant instantinated" << endl;
        cout << e.what() << endl;
    }
    return 0;
}
