#if !defined(SHRUBBERY_CREATION_FORM)
#define SHRUBBERY_CREATION_FORM

# include "common.hpp"
# include "AForm.hpp"
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

# define ASCII_TREE "\
........................................................................................................................\n\
........................................................................................................................\n\
........................................................................................................................\n\
........................................................................................................................\n\
........................................................................................................................\n\
........................................................................................................................\n\
.........................................................=...=..........................................................\n\
......................................................=.====.===.=.=....................................................\n\
....................................................========.==========.................................................\n\
...............................................===========I================.............................................\n\
.........................................=....========I===II=I=I=III=I======............................................\n\
.........................................=.=.======I==III=II=III=II==I======............................................\n\
.......................................=.==========II=IIIIII=I=IIII=I=====I=.===........................................\n\
.....................................=..========I===IIIIIIII=IIIIII=I=I==II======.==....................................\n\
.....................................============I=II=IIIIIIIAIIIAI=I====II========.==..................................\n\
....................................=====I=I===I=.=III=IIIIAAIIIIAI=I==IIII============.................................\n\
.....................................=====II==III==IIAI=IIIAII=AIAIII=IIII===II=======..................................\n\
...................................==.======II=III==IAIIIIIAII=AAIII=II==I===II=I=====.==.=.............................\n\
....................................========IIIIIII=IIAIIIAAIIIIAIII==I==I==IIIII==I===.===.............................\n\
.............................=....=========IIIIIIIIIIIAIIAAAIIIIAIII=IAIII=IIIIIIII=========..==........................\n\
..............................===.======I===IIAAAIIIIAAAIAAAAIAIAIIIIIAIIIAIIAAI======.=======.==.......................\n\
............................===I===========IIIIAAAIIIIAAAAAAAIAIAIAI=II=IAAIII===I==============........................\n\
..............................==I======III==IIIIIIAAI=AAIAAXAAAAIAAIIAAIAAIIIIII=I===IIII======....=....................\n\
............................=..=IAI===IIIIIIIIIIIAAAAAIAIXIXAAXAIAXAAIIAAAIIAII=IIIIIII=======..===.....................\n\
...........................====..IAII=IIIII=IIIIAIAIAAAAAXAXAAXAIAAAIAAAAIIIAIIIIIIIIII=====.=.===......................\n\
..................=........=======IIIIIIIIIAIIIIIIIAAXAAAXAAXXXAIXAIAXIAAA=AIIA==I=II=====I=====........................\n\
..................==......=========IIAIIIAIIIIAAAIIIAAAAAXAXXXXAAXAAAAAAAIAIIII==III=======.=========...................\n\
...................=I==..=====I======IIIIIAAIAIIIAAAAAXXAXXXXAXAAXAXXIAAIAIIIIIIAII==.==IIII==III===....................\n\
....................=II===I====IIIIIIIAAAAIAAAAAIIIAXXXXXXXXXXXAAAAAAAXAAAAAAAAIIIIIAAAAIIIIII====......................\n\
....................==IIIIIIIIIIIIAAAAAAXAAAAIIIAIIIAXXXMXXXMXAAXXIAXAAXAAAAIII=IIII======IIII=I=====...................\n\
................==..====IIIIAAAIIIIAIAAAAAXAAXAIIIAAAIXAAMXMMMXXAAXXXXXXAIIIIIIAIIIIIIIIIIIIIII========.................\n\
...............=====I====IIAAAAAIII=====IIAXXAXXAAIAAAAXIAMMXMXAAAXMMXAIIAAAI=====IIIIIIIAII========....................\n\
...................=====IIIIIIAAAAAAAIIIIIIAAAIAAXMMXXXXXXMMXMMXXMMXAIAAAAAIII====IIAAAAIIII====.=.........=............\n\
...................========IIIIIAXXAAAIIAIIIIIAAAIAXAAAXAXXMMMXXMMMAAIAAAAAAIAIIIIAAAIAIII==========..=====.............\n\
................=======II=========IAAAAXXXXAAAAAXXAAXAAIXMMMMXXMMMAIAAAAIAAXXAAAAAII==II=========..======...............\n\
..........========.======IIIIIIIIIIIAAAXXXXXXXXAAXXXXXXXAXMMMMMMXXAAAXAAAAAXAAAAAIIIIIIIIIIIIIIIIIII===.................\n\
............===IIIAIIIIIIIIAIAAAAXXXXXXXXXXXXXAXXAXAXXMXXMMMMMMXMXXXXAAAAAAAIIAIIAAAAAAIAAIIIIIII=====..................\n\
................=======IIIIIIIAAAAAAAAAXAXAAAAXMMMXXAAMXIAMMMMMMMXMXXXXXXXXXXXAAAIIIIIIIIIIIIAII========................\n\
.................====II==I=IIIIIIIIAIAAXAAAAXXXXXXXMXXXMMAMMMMXIAXXAAXXXXXXXXXXAAAAAAAAAIAAIIIIII=====..................\n\
...............====================IIIAAAXAXXXXXAXXMMMMMXMMWMMMMXXXXXAAAAAAIAAXXXAAAAAII================................\n\
.....................==...======IIIAAAXXXAAAAXAXIAAIAXMMAAMWWMXAXAAXXXAXAAXXAXAXXXAIIIIIII====I=======.=................\n\
..................=====IIIIIIAAAAAAAAAAAI=IAIAAA=IIAXXAXMXMMMXIAAAAXXXXXAXAIAAAAAAAAAAAAIIIII==========.................\n\
.................=====IIIIIIAAAIIIII=I=IIIIAXAAIAAIAXXXAIMMMMXIAIAAXXXAAXXXXXAIIIAAAIAAIAIIIII=====I====................\n\
.................=======III=I======IIIIIIIAXAAAAIIAAIIIAAAMMMAAAAAIIIAXXXMXXXXAIII==IIIII==IIIII=======.................\n\
................=================II==IIIAAAAAAAIIAI===IIIMMMMXAIIAIIIIIAAXXXXXXXAAII==IIII========.====.................\n\
..................====..=============IIAAAAAIIIIIII===IIIXMMMAIIAIIAIII=IAAAAAXXAAIIAII==============...................\n\
........................============IAAAIAII===I======I==AMMMAIII=IAI====IIIAAAAAAAAIIIIIII===========..................\n\
......................======..======III===II============IIMMMIIIIIII=====I===IAAAAIAAI=I========........................\n\
===================.....==....==============I=============MMMI=================IIAAIIIIIIII========.....................\n\
==========================.....================..=========MMMI===================IIIIII====I==.==.......................\n\
==============================================....========MMMI=.......=================I===I====........................\n\
================================================..=.======MMMA==......==.=.......===..===.===.==........................\n\
==========================================================MMMA=================.=========..==.......=========...........\n\
==========================================================MMMX==========================================================\n\
=========================================================IMMMX==========================================================\n\
========II==IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIAAAIIAIIXMMMMAIIIIAAAIIIIIIIIIIIIIII=IIIII=IIIIIIIIIIII================\n\
XXXXXXXXXXXXXXXXXXXXXXXXXXMXXXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXMMM\n\
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMWMMMMMWWWWMMWWWWWWWWWWWWMWMWMMWMMWMMMMWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\
"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(string target);
		ShrubberyCreationForm(AForm &cp);
		ShrubberyCreationForm& operator=(AForm &assgn);
		~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
};

#endif // SHRUBBERY_CREATION_FORM
