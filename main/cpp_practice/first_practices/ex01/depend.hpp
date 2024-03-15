/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depend.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/03/15 12:20:12 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DEPEND_H
# define DEPEND_H
# if defined(__linux__)
/* Linux. --------------------------------------------------- */

# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */

# endif

# include <iostream>
# include <iomanip>

# define RED				"\x1B[31m"
# define GREEN				"\x1B[32m"
# define YELLOW				"\x1B[33m"
# define BLUE				"\x1B[34m"
# define RESET				"\x1B[0m"

# define PREFIX				"\n" YELLOW "Enter the "
# define ENTER				"cmd"
# define SUFFIX				"> " RESET

# define WELCOME			"============welcome============"

# define CMD1				BLUE "ADD" RESET
# define CMD2				BLUE "SEARCH" RESET
# define CMD3				BLUE "EXIT" RESET

# define ADD_S				"ADD"
# define SEARCH_S			"SEARCH"
# define EXIT_S				"EXIT"


# define PREFIX2			"- "
# define INDENT				GREEN "	"
# define END_DES			"\n" RESET
# define CMD_LST			PREFIX2 CMD1 END_DES \
							CMD1_DES \
							PREFIX2 CMD2 END_DES \
							CMD2_DES \
							PREFIX2 CMD3 END_DES \
							CMD3_DES

# define CMD1_DES			INDENT "add a contact." END_DES
# define CMD2_DES			INDENT "search a contact." END_DES
# define CMD3_DES			INDENT "close cleanest way to program." END_DES

# define FNAME				"FNAME"
# define LNAME				"LNAME"
# define NNAME				"NNAME"
# define PNUME				"PNUME"
# define sec				"secret"

# define PROMPT_FNAME		PREFIX "first name" SUFFIX
# define PROMPT_LNAME		PREFIX "last name" SUFFIX
# define PROMPT_NNAME		PREFIX "nick name" SUFFIX
# define PROMPT_PHONE		PREFIX "phone number" SUFFIX
# define PROMPT_SEC			PREFIX "secret darkest secret" SUFFIX

# define INVALID_SELECTION	RED "Invalid command" RESET

# define ERR_ADD			"could not be added"
# define SUCC_ADD			"The contact has been added"
# define SUCC_SEARCH		"Results"
# define ERR_SEARCH			"could not be found"
# define INVALID_SEARCH		"Invalid index!! >:{ "
# define ASK_INDEX			YELLOW "Enter index" RESET
# define SUCC_EXIT			"bYe bYe"

# define NORMAL_COLOR		GREEN
# define NORMAL_BLANK		' '
# define NORMAL_TEDGE		'#'
# define NORMAL_BEDGE		'#'
# define NORMAL_LEDGE		"["
# define NORMAL_REDGE		"]"
# define NORMAL_WLEDGE		"["
# define NORMAL_WREDGE		"]"
# define NORMAL_LTCORNER	"/"
# define NORMAL_RTCORNER	"\\"
# define NORMAL_RBCORNER	"/"
# define NORMAL_LBCORNER	"\\"
# define NORMAL_SEPARATOR	"|"
# define NORMAL_ALIGN		right
# define NORMAL_HEAD_ALIGN	left
# define NORMAL_FOOT_ALIGN	left
# define NORMAL_KEY_SIZE	10
# define NORMAL_VALUE_SIZE	10
						// [HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH]
						// [----------|----------|------------|----------]
# define NORMAL_HEAD_SIZE	1 + NORMAL_KEY_SIZE + 1 + NORMAL_KEY_SIZE + 1 + NORMAL_KEY_SIZE + 1 + NORMAL_VALUE_SIZE + 0
# define NORMAL_FOOT_SIZE	NORMAL_HEAD_SIZE
# define NORMAL_WALL_SIZE	NORMAL_HEAD_SIZE
# define NORMAL_WALL		'-'	




# define DETAIL_ALIGN		left
# define DETAIL_HEAD_ALIGN	left
# define DETAIL_FOOT_ALIGN	left
# define DETAIL_KEY_SIZE	16
# define DETAIL_VALUE_SIZE	32
						// [HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH]
						// [----------------------|-----------------------]
# define DETAIL_HEAD_SIZE	1 + DETAIL_KEY_SIZE + 1 + DETAIL_VALUE_SIZE + 0
# define DETAIL_FOOT_SIZE	DETAIL_HEAD_SIZE
# define DETAIL_WALL_SIZE	DETAIL_HEAD_SIZE
# define DETAIL_WALL		'^'	
# define DETAIL_COLOR		RESET
# define DETAIL_BLANK		'-'
# define DETAIL_TEDGE		'&'
# define DETAIL_BEDGE		'$'
# define DETAIL_LEDGE		"<"
# define DETAIL_REDGE		">"
# define DETAIL_WLEDGE		""
# define DETAIL_WREDGE		""
# define DETAIL_LTCORNER	"A"
# define DETAIL_RTCORNER	"B"
# define DETAIL_RBCORNER	"C"
# define DETAIL_LBCORNER	"D"
# define DETAIL_SEPARATOR	"@"

# define CEIL				BLUE
# define FLOOR				BLUE

# define CEIL2				RED
# define FLOOR2				RED


# define MAX_CONTACTS		8
# define MAX_PROPERTY		5

// [###########################################]
// [         0| 000111000|0001110001|000111000.]
// [-------------------------------------------]
// [         1|         r|         r|         r]
// [-------------------------------------------]
// [         2|          |          |          ]
// [-------------------------------------------]
// [         3|          |          |          ]
// [-------------------------------------------]
// [         4|          |          |          ]
// [-------------------------------------------]
// [         5|          |          |          ]
// [-------------------------------------------]
// [         6|          |          |          ]
// [-------------------------------------------]
// [         7|          |          |          ]
// [###########################################]

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::stoi;

typedef enum option {
	ADD,
	SEARCH,
	EXIT,
	DEFAULT
}   t_option;

/**
 *  @struct t_order s_order
 *  @brief Filter structure 
 *	@memberof s_order::seq
 *	@var s_order::seq 
 */

string truncate(string str, size_t width, bool show_ellipsis);
int printFloor();
int printCeiling();
int printFloor2();
int printCeiling2();
int wall_wextra();
int wall_wextra2();

#endif
