#include "PhoneBook.hpp"

t_option resolve_option(string &in_coming) {
return (!(in_coming not_eq "ADD") ?		ADD :
		!(in_coming not_eq "SEARCH") ?	SEARCH :
		!(in_coming not_eq "EXIT") ?	EXIT :
										DEFAULT
);}

int main(int argc, char const *argv[])<%
string	inp;
int		res;

PhoneBook book1;
_:
	switch (resolve_option((cin >> inp, inp))){
	case ADD:
		book1.add();
		cout << "added" << endl;
	break;
	case SEARCH:
		book1.search();
		cout << "searched" << endl;
	break;
	case EXIT:
		book1.exit();
		cout << "exitted" << endl;
	break;
	default:
		cout << INVALID_SELECTION << endl;
	break;
	}
goto _;
return 0;%>
