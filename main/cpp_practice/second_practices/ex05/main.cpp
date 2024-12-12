#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    Harl a;
    a.complain("DEBUG");
    a.complain("INFO");
    a.complain("WARNING");
    a.complain("ERROR");
    a.complain("FATAL");
    return 0;
}
