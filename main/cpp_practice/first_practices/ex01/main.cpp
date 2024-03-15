#include "PhoneBook.hpp"

int printCeiling(){
cout	<< (CEIL "")
		<< std::NORMAL_HEAD_ALIGN
		<< setw(NORMAL_HEAD_SIZE)
		<< std::setfill(NORMAL_TEDGE)
		<< NORMAL_LTCORNER
		<< NORMAL_RTCORNER
		<< RESET
		<< endl;
return 0;}

int printFloor(){
cout	<< (FLOOR "")
		<< std::NORMAL_FOOT_ALIGN
		<< setw(NORMAL_FOOT_SIZE)
		<< std::setfill(NORMAL_BEDGE)
		<< NORMAL_LBCORNER
		<< NORMAL_RBCORNER
		<< RESET
		<< endl;
return 0;}

int printCeiling2(){
cout	<< (CEIL2 "")
		<< std::DETAIL_HEAD_ALIGN
		<< setw(DETAIL_HEAD_SIZE)
		<< std::setfill(DETAIL_TEDGE)
		<< DETAIL_LTCORNER
		<< DETAIL_RTCORNER
		<< RESET
		<< endl;
return 0;}

int printFloor2(){
cout	<< (FLOOR2 "")
		<< std::DETAIL_FOOT_ALIGN
		<< setw(DETAIL_FOOT_SIZE)
		<< std::setfill(DETAIL_BEDGE)
		<< DETAIL_LBCORNER
		<< DETAIL_RBCORNER
		<< RESET
		<< endl;
return 0;}

int wall_wextra(){
cout	<< (DETAIL_COLOR "")
		<< endl
		<< DETAIL_WLEDGE
		<< setw(DETAIL_WALL_SIZE)
		<< std::setfill(DETAIL_WALL)
		<< DETAIL_WREDGE
		<< RESET
		<< endl;
return 0;}

int wall_wextra2(){
cout	<< (NORMAL_COLOR "")
		<< endl
		<< NORMAL_WLEDGE
		<< setw(NORMAL_WALL_SIZE)
		<< std::setfill(NORMAL_WALL)
		<< NORMAL_WREDGE
		<< RESET
		<< endl;
return 0;}

// https://stackoverflow.com/a/19590797
string truncate(string str, size_t width, bool show_ellipsis){
if (str.length() > width){
	if (show_ellipsis){
		return str.substr(0, width).replace(NORMAL_KEY_SIZE - 1, NORMAL_KEY_SIZE - 1, ".");
	}
	else
		return str.substr(0, width);
}
return str;}

t_option resolve_option(string &in_coming) {
t_option	res;

res = !(in_coming not_eq ADD_S) ?		ADD :
		!(in_coming not_eq SEARCH_S) ?	SEARCH :
		(!(in_coming not_eq EXIT_S)) || \
		(cin.eof()) ?					EXIT :
										DEFAULT;
in_coming.clear();
return ( res );}

int main(int argc, char const *argv[]){
string	cmd_inp;
PhoneBook book1;
______________________________________________________________:
	switch (resolve_option((cin >> (cout << PREFIX ENTER SUFFIX, cmd_inp), cmd_inp))){
	case ADD:
		if (!book1.add()){
			cout << SUCC_ADD << endl;
			break;}
		cerr << endl << endl << ERR_ADD << endl;
		clearerr(stdin);
		cin.clear();
	break;
	case SEARCH:
		if(!book1.search()){
			cout << SUCC_SEARCH << endl;
			break;}
		cout << ERR_SEARCH << endl;
		clearerr(stdin);
		cin.clear();
	break;
	case EXIT:
		book1.exit();
		return EXIT_SUCCESS;
	break;
	default:
		cerr << INVALID_SELECTION << endl << CMD_LST;
	break;}
goto
______________________________________________________________;
return EXIT_SUCCESS;}
