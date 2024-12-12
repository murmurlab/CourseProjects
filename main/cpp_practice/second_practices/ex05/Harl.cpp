#include <iostream>
#include "Harl.hpp"


void Harl::debug(){
    cout<< "debug "<<endl;
}

void Harl::info(){
    cout<< "info "<<endl;
}

void Harl::warning(){
    cout<< "warning "<<endl;
}

void Harl::error(){
    cout<< "error "<<endl;
}

void Harl::complain( std::string level ){
string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
void (Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
size_t i;
for (i = 0; i < 4; i++){
    if (levels[i] == level)    
        break;
}
if (i == 4)
    return;
(this->*funcs[i])();
}