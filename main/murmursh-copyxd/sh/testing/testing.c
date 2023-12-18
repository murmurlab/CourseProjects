#include "testing.h"

void run_test()
{
    printf(BLUE"\n\n===================murminette====================\n");
    printf(BLUE"=================================================\n"RESET);
    printf(BLUE"=====================len_all=====================\n"RESET);
    printf(BLUE"=================================================\n"RESET);

    char    *str = "$$";
    size_t  tmp;
    size_t  _;
    int  i = 0;
    t_list *tm;
    t_list *tm2;
    size_t  dollar = 4;
    char    *result[2] = {GREEN"[OK]"RESET, RED"[KO]"RESET};
    char    *complex_len_tests[][2] = {
        {"$$", (void *)2}, // 0
        {"$a", (void *)0}, // 1
        {"$$a", (void *)1}, // 2
        {"$", (void *)1}, // 3
        {"$a$", (void *)0}, // 4
        {"1", (void *)1}, // 5
        {"", (void *)0}, // 6
        {"\"$$\"", (void *)2}, // 7
        {"\"$a\"", (void *)4}, // 8
        {"\"$$a\"", (void *)5}, // 9
        {"\"$\"", (void *)1}, // 10
        {"\"$a$\"", (void *)5}, // 11
        {"\"", (void *)0}, // 12
        {"\"1\"", (void *)1}, // 13
        {"a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$", (void *)30}, // 14
        {"\"a$a99-$a\"", (void *)6}, // 15
        {"123123'123'1\"12\"1", (void *)13}, // 16
        {"1$a'$a'\"\"1\"\"$a''$a $a", (void *)1}, // 17
        {"\"a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$\"", (void *)3}, // 18
        {(void *)0, (void *)0}
    };
    char    *expand_tests[][4] = {
        // "a$a=$a99"$-$'$'$''$""$"$"$-$-$$-$$=11$$

        {"\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$", "a0000=", (void *)10, (void *)6},
        {"\"ast\"", "ast", (void *)5, (void *)(3)},
        {"\"\"", "", (void *)2, (void *)(0)},
        {"\"$a\"", VAR, (void *)4, (void *)(0 + VAR_LEN)},
        {"\"$a1\"", "", (void *)5, (void *)0},
        {"\"$-\"", "$-", (void *)4, (void *)2},
        {"\"$\"", "$", (void *)3, (void *)1},
        {"\"$$\"", "$$", (void *)4, (void *)2},
        {"\"1$a\"", "1"VAR, (void *)5, (void *)(1 + VAR_LEN)},
        {"\"-$\"", "-$", (void *)4, (void *)2},
        {"\"a$\"", "a$", (void *)4, (void *)2},
        
        {"\"$$$\"", "$$$", (void *)5, (void *)3}, //len test
        {"\"$a-\"", VAR"-", (void *)5, (void *)(VAR_LEN + 1)},
        {"\"$$a\"", "$"VAR, (void *)5, (void *)(1 + VAR_LEN)},
        {"\"$a-$\"", VAR"-$", (void *)6, (void *)(VAR_LEN + 2)},
        {"\"$a-$$\"", VAR"-$$", (void *)7, (void *)(VAR_LEN + 3)},
        {"\"-$-$-$\"", "-$-$-$", (void *)8, (void *)6},
        {"\"-$a$a99\"", "-"VAR, (void *)9, (void *)(1 + VAR_LEN)},
        {"\"-$a$a$a\"", "-"VAR VAR VAR, (void *)9, (void *)(1 + (VAR_LEN * 3))},
        {"\"$a-$a\"", VAR"-"VAR, (void *)7, (void *)(VAR_LEN + 1 + VAR_LEN)},
        // {"a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$", "a$a0000=$-$$$$$$$$-$-$$-$$=11$$", (void *)42, (void *)30}, // 14

        {(void *)0, (void *)0}
    };
    char    *mix[][4] = {
        {"a$", "a$a0000=$-$$$$$$$-$-$$-$$=11$$", (void *)42, (void *)30}, // 14
        {"a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$", "a$a0000=$-$$$$$$$-$-$$-$$=11$$", (void *)42, (void *)30}, // 14
        {"a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$", "a$a0000=$-$$$$$$$-$-$$-$$=11$$", (void *)42, (void *)30}, // 14
        {"a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$", "a$a0000=$-$$$$$$$-$-$$-$$=11$$", (void *)42, (void *)30}, // 14

        {(void *)0, (void *)0}
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
    // ============================complex_len_test=============================
    while (complex_len_tests[i][0])
    {
        data->line = complex_len_tests[i][0];
        printf("line: %s\n", data->line);
        if (len_all(data, 0) == (size_t)complex_len_tests[i][1])
            printf("=================TEST %d=%s================\n", i, result[0]);
        else
        {
            ft_lstadd_back(&root, ft_lstnew((void *)(size_t)i));
            printf(YELLOW"expected %zu\n"RESET, (size_t)complex_len_tests[i][1]);
            printf("^^^^^^^^=========TEST %d=%s================\n", i, result[1]);
        }
        i++;
    }
    printf(BLUE"\n\n=================================================\n"RESET);
    printf(BLUE"==================dquote expand==================\n"RESET);
    printf(BLUE"=================================================\n"RESET);
    // ===============================expand_test===============================
    i = 0;
    size_t  *sonuc;
    char    *buffer;
    char     err = 0;
    while (expand_tests[i][0])
    {
        data->line = expand_tests[i][0];
        printf("[=====================TEST %d=====================]\n", i);
        printf("    line: %s\n", data->line);
        buffer = calloc(strlen(expand_tests[i][0]), 4);
        sonuc = expander_exp(data, buffer, 0);
        // printf("sonuc: %s\n", buffer);
        if (strcmp(expand_tests[i][1], buffer))
        {
            err |= 0b00000001;
            printf("⋁⋁⋁⋁⋁⋁⋁⋁--------------str-%s---------------------\n", result[1]);
            printf(YELLOW"expected %s\n"RESET, expand_tests[i][1]);
            printf(YELLOW"result %s\n"RESET, buffer);
        }
        else
        {
            printf("----------------------str-%s---------------------\n", result[0]);
            printf(GREEN"expected %s\n"RESET, expand_tests[i][1]);
            printf(GREEN"result %s\n"RESET, buffer);
        }

        if (sonuc[0] != (size_t)expand_tests[i][2])
        {
            err |= 0b00000010;
            printf("⋁⋁⋁⋁⋁⋁⋁⋁----------len normal-%s------------------\n", result[1]);
            printf(YELLOW"expected %zu\n"RESET, (size_t)expand_tests[i][2]);
            printf(YELLOW"result %zu\n"RESET, sonuc[0]);
        }
        else
        {
            printf("-------------------len normal-%s-----------------\n", result[0]);
            printf(GREEN"expected %zu\n"RESET, (size_t)expand_tests[i][2]);
            printf(GREEN"result %zu\n"RESET, sonuc[0]);
        }

        if (sonuc[1] != (size_t)expand_tests[i][3])
        {
            err |= 0b00000100;
            printf("⋁⋁⋁⋁⋁⋁⋁⋁--------len expanded-%s------------------\n", result[1]);
            printf(YELLOW"expected %zu\n"RESET, (size_t)expand_tests[i][3]);
            printf(YELLOW"result %zu\n"RESET, sonuc[1]);
        }
        else
        {
            printf("-----------------len expanded-%s-----------------\n", result[0]);
            printf(GREEN"expected %zu\n"RESET, (size_t)expand_tests[i][3]);
            printf(GREEN"result %zu\n"RESET, sonuc[1]);
        }
        printf("[===================TEST %d=%s==================]\n\n\n\n", i, result[0 || err]);

        free(sonuc);
        free(buffer);
        i++;
        err = 0;
    }

    printf(BLUE"==================================================\n"RESET);
    printf(BLUE"=====================Join ALL=====================\n"RESET);
    printf(BLUE"==================================================\n\n\n"RESET);

    i = 0;
    while (mix[i][0])
    {
        data->line = mix[i][0];
        printf("[=====================TEST %d=====================]\n", i);
        printf("    line: %s\n", data->line);
        buffer = calloc(strlen(mix[i][0]), 4);
        buffer = join_all(data, 0);
        // printf("sonuc: %s\n", buffer);
        if (strcmp(mix[i][1], buffer))
        {
            err |= 0b00000001;
            printf("⋁⋁⋁⋁⋁⋁⋁⋁--------------str-%s---------------------\n", result[1]);
            printf(YELLOW"expected %s\n"RESET, mix[i][1]);
            printf(YELLOW"result %s\n"RESET, buffer);
        }
        else
        {
            printf("----------------------str-%s---------------------\n", result[0]);
            printf(GREEN"expected %s\n"RESET, mix[i][1]);
            printf(GREEN"result %s\n"RESET, buffer);
        }

        // if (sonuc[0] != (size_t)expand_tests[i][2])
        // {
        //     err |= 0b00000010;
        //     printf("⋁⋁⋁⋁⋁⋁⋁⋁----------len normal-%s------------------\n", result[1]);
        //     printf(YELLOW"expected %zu\n"RESET, (size_t)expand_tests[i][2]);
        //     printf(YELLOW"result %zu\n"RESET, sonuc[0]);
        // }
        // else
        // {
        //     printf("-------------------len normal-%s-----------------\n", result[0]);
        //     printf(GREEN"expected %zu\n"RESET, (size_t)expand_tests[i][2]);
        //     printf(GREEN"result %zu\n"RESET, sonuc[0]);
        // }

        // if (sonuc[1] != (size_t)expand_tests[i][3])
        // {
        //     err |= 0b00000100;
        //     printf("⋁⋁⋁⋁⋁⋁⋁⋁--------len expanded-%s------------------\n", result[1]);
        //     printf(YELLOW"expected %zu\n"RESET, (size_t)expand_tests[i][3]);
        //     printf(YELLOW"result %zu\n"RESET, sonuc[1]);
        // }
        // else
        // {
        //     printf("-----------------len expanded-%s-----------------\n", result[0]);
        //     printf(GREEN"expected %zu\n"RESET, (size_t)expand_tests[i][3]);
        //     printf(GREEN"result %zu\n"RESET, sonuc[1]);
        // }
        printf("[===================TEST %d=%s==================]\n\n\n\n", i, result[0 || err]);

        // free(sonuc);
        free(buffer);
        i++;
        err = 0;
    }

    tm = root;
    printf(BLUE"=============================================\n"RESET);
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
