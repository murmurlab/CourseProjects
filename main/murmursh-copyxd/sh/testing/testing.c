#include "testing.h"

void run_test()
{
    printf("===========================TEST================================\n");
    char    *str = "$$";
    size_t  tmp;
    size_t  _;
    int  i = 0;
    t_list *tm;
    t_list *tm2;
    size_t  dollar = 4;
    char    *result[2] = {GREEN"[OK]"RESET, RED"[KO]"RESET};
    char    *tests[] = {
        "$$",
        "$a",
        "$$a",
        "$",
        "$a$",
        "1",
        "", // 6
        
        "\"$$\"",
        "\"$a\"",
        "\"$$a\"",
        "\"$\"",
        "\"$a$\"",
        "\"", // 12
        "\"1\"",
        "a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$",
        "\"a$a99-$a\"",
        "123123'123'1\"12\"1",
        "1$a'$a'\"\"1\"\"$a''$a $a",
        "\"a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$\"",
        0
    };
    size_t  expected[] =
    {
        2, // 4
        0, // 5
        1, // 6
        1, // 7
        0, // 8
        1, // 9
        0, // 10
        2, // 11
        4, // 12
        5, // 13
        1, // 14
        5, // 15
        0, // 12 12
        1, // 16
        30, // 0
        6, // 1
        13, // 2
        1, // 3
        3, // 18
    };
    _ = 0;
    t_main *data = malloc(sizeof(t_main));
    // tmp = var_name_len("aaa");
    // printf("var_name_len: %zu\n", tmp);
    // printf("%d\n", (is_text(str[_]) && !((str[_] == '$') && is_var(str[_ + 1]))));
    ft_bzero(data->increases, INT8_MAX);
    data->increases['"'] = (char)2;
	data->increases['\''] = (char)2;
	data->increases[0] = (char)0;
	data->vars = NULL;
	set(data, strdup("a"), strdup("0000"));

    t_list *root = NULL;
    while (tests[i])
    {
        data->line = tests[i];
        printf("line: %s\n", data->line);
        if (len_all(data, 0) == expected[i])
            printf("=================TEST %d=%s================\n", i, result[0]);
        else
        {
            ft_lstadd_back(&root, ft_lstnew((size_t)i));
            printf(YELLOW"expected %zu\n"RESET, expected[i]);
            printf("^^^^^^^^=========TEST %d=%s================\n", i, result[1]);
        }
        i++;
    }
    tm = root;
    printf(BLUE"\n\n=============================================\n"RESET);
    printf(BLUE"==================SUMMARY====================\n"RESET);
    // print error tests.
    while (root)
    {
        printf(YELLOW"error test: %zu"RESET, (size_t)(root->content));
        if (root->next)
            printf(", ");
        else
            printf("\n");
        root = root->next;
    }
    // clear lst
    while (tm)
    {
        tm2 = tm;
        tm = tm->next;
        // free(tm2);
    }
    
    // make leak for fsanitize=address
    // tm = 0;
    // tm2 = 0;
    
    printf(BLUE"=============================================\n"RESET);
    printf(BLUE"=============================================\n"RESET);
    
	exit(0);
}
