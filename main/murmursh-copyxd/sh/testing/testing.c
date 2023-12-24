#include "testing.h"

void	complex_len_test_ko(t_test *test)
{
	char    *result[2] = {GREEN"[OK]"RESET, RED"[KO]"RESET};
	printf(YELLOW"expected %zu\n"RESET, (size_t)(test->current_test->trys->expected));
	printf("^^^^^^^^=========TEST %zu=%s================\n", test->test_number, result[1]);
}

void	complex_len_test_ok(t_test *test)
{
	char    *result[2] = {GREEN"[OK]"RESET, RED"[KO]"RESET};
	printf("=============== %s ================\n", test->current_test->name);
    printf("try         [ %s ]\n", test->current_test->trys->try);
    printf("expected    [ %zu ]\n", (size_t)test->current_test->trys->expected);
	printf("=================TEST %zu=%s================\n\n\n", test->test_number, result[0]);
}

int		complex_len_test(t_test *test)
{
    printf("log %p\n", 0);
	// len_all(test->my_data, 0xffffffff) offset degis
	((t_main *)(test->my_data))->line = test->current_test->trys->try;
    size_t  neverdin = len_all(test->my_data, 0);
	if (neverdin == (size_t)test->current_test->trys->expected)
		return (1);
	return (0);
}

void	expand_test_ko(t_test *test)
{
	char    *result[2] = {GREEN"[OK]"RESET, RED"[KO]"RESET};
	printf(YELLOW"expected %zu\n"RESET, (size_t)(test->current_test->trys->expected));
	printf("^^^^^^^^=========TEST %zu=%s================\n", test->test_number, result[1]);
}

void	expand_test_ok(t_test *test)
{
	char    *result[2] = {GREEN"[OK]"RESET, RED"[KO]"RESET};
	printf("=============== %s ================\n", test->current_test->name);
    printf("try         [ %s ]\n", test->current_test->trys->try);
    printf("expected    [ %zu ]\n", (size_t)test->current_test->trys->expected);
	printf("=================TEST %zu=%s================\n\n\n", test->test_number, result[0]);
}

int     expand_test(t_test *test)
{
    char    *buffer;
    size_t  *sonuc;
    
    printf("log %p\n", 0xffff);
    ((t_main *)(test->my_data))->line = test->current_test->trys->try;
    buffer = calloc(strlen(test->current_test->trys->try), 2);
    sonuc = expander_exp(test->my_data, buffer, 0);
    if (strcmp(((void **)test->current_test->trys->expected)[0], buffer))
        return (0);
    return (1);
}

void	all_tests()
{
    // init minishell dependends
	t_main *data = malloc(sizeof(t_main));
	ft_bzero(data->increases, INT8_MAX);
	data->increases['"'] = (char)2;
	data->increases['\''] = (char)2;
	data->increases[0] = (char)0;
	data->vars = NULL;
	set(data, strdup("a"), strdup("0000"));


    // create test struct
	t_test	test;
	test.my_data = data;
    
	t_try	*trys[] =
	{
		(t_try [])
		{
            {
                .try = &(t_fun){complex_len_test, complex_len_test_ko, complex_len_test_ok},
                .expected = "complex len test",
            },
			{
				.try = "$$",
				.expected = (void *)2,
			},
			{
				.try = "$a",
				.expected = (void *)0,
			},
			{
				.try = "$$a",
				.expected = (void *)1,
			},
			{
				.try = "$",
				.expected = (void *)1,
			},
			{
				.try = "$a$",
				.expected = (void *)0,
			},
			{
				.try = "1",
				.expected = (void *)1,
			},
			{
				.try = "",
				.expected = (void *)0,
			},
			{
				.try = "\"$$\"",
				.expected = (void *)2,
			},
			{
				.try = "\"$a\"",
				.expected = (void *)4,
			},
			{
				.try = "\"$$a\"",
				.expected = (void *)5,
			},
			{
				.try = "\"$\"",
				.expected = (void *)1,
			},
			{
				.try = "\"$a$\"",
				.expected = (void *)5,
			},
			{
				.try = "\"\"",
				.expected = (void *)0,
			},
			{
				.try = "\"1\"",
				.expected = (void *)1,
			},
			{
				.try = "a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$",
				.expected = (void *)30,
			},
			{
				.try = "\"a$a99-$a\"",
				.expected = (void *)6,
			},
			{
				.try = "123123'123'1\"12\"1",
				.expected = (void *)13,
			},
			{
				.try = "1$a'$a'\"\"1\"\"$a''$a $a",
				.expected = (void *)1,
			},
			{
				.try = "\"a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$\"",
				.expected = (void *)3,
			},
			{
				.try = NULL,
				.expected = NULL,
			}
		},
		(t_try [])
		{
            {
                .try = &(t_fun){expand_test, expand_test_ko, expand_test_ok},
                .expected = "dquote test",
            },
			{
                .try = "\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$",
                .expected = &(void *[3]){
                    "a0000=",
                    (void *)10,
                    (void *)6
                }
            },
            {
                .try = "\"ast\"",
                .expected = &(void *[3]){
                    "ast",
                    (void *)5,
                    (void *)3
                }
            },
            {
                .try = "\"\"",
                .expected = &(void *[3]){
                    "",
                    (void *)2,
                    (void *)0
                }
            },
            {
                .try = "\"$a\"",
                .expected = &(void *[3]){
                    VAR,
                    (void *)4,
                    (void *)(0 + VAR_LEN)
                }
            },
            {
                .try = "\"$a1\"",
                .expected = &(void *[3]){
                    "",
                    (void *)5,
                    (void *)0
                }
            },
            {
                .try = "\"$-\"",
                .expected = &(void *[3]){
                    "$-",
                    (void *)4,
                    (void *)2
                }
            },
            {
                .try = "\"$\"",
                .expected = &(void *[3]){
                    "$",
                    (void *)3,
                    (void *)1
                }
            },
            {
                .try = "\"$$\"",
                .expected = &(void *[3]){
                    "$$",
                    (void *)4,
                    (void *)2
                }
            },
            {
                .try = "\"1$a\"",
                .expected = &(void *[3]){
                    "1"VAR,
                    (void *)5,
                    (void *)(1 + VAR_LEN)
                }
            },
            {
                .try = "\"-$\"",
                .expected = &(void *[3]){
                    "-$",
                    (void *)4,
                    (void *)2
                }
            },
            {
                .try = "\"a$\"",
                .expected = &(void *[3]){
                    "a$",
                    (void *)4,
                    (void *)2
                }
            },
            {
                .try = "\"$$$\"",
                .expected = &(void *[3]){
                    "$$$",
                    (void *)5,
                    (void *)3
                } //len test
            },
            {
                .try = "\"$a-\"",
                .expected = &(void *[3]){
                    VAR"-",
                    (void *)5,
                    (void *)(VAR_LEN + 1)
                }
            },
            {
                .try = "\"$$a\"",
                .expected = &(void *[3]){
                    "$"VAR,
                    (void *)5,
                    (void *)(1 + VAR_LEN)
                }
            },
            {
                .try = "\"$a-$\"",
                .expected = &(void *[3]){
                    VAR"-$",
                    (void *)6,
                    (void *)(VAR_LEN + 2)
                }
            },
            {
                .try = "\"$a-$$\"",
                .expected = &(void *[3]){
                    VAR"-$$",
                    (void *)7,
                    (void *)(VAR_LEN + 3)
                }
            },
            {
                .try = "\"-$-$-$\"",
                .expected = &(void *[3]){
                    "-$-$-$",
                    (void *)8,
                    (void *)6
                }
            },
            {
                .try = "\"-$a$a99\"",
                .expected = &(void *[3]){
                    "-"VAR,
                    (void *)9,
                    (void *)(1 + VAR_LEN)
                }
            },
            {
                .try = "\"-$a$a$a\"",
                .expected = &(void *[3]){
                    "-"VAR VAR VAR,
                    (void *)9,
                    (void *)(1 + (VAR_LEN * 3))
                }
            },
            {
                .try = "\"$a-$a\"",
                .expected = &(void *[3]){
                    VAR"-"VAR,
                    (void *)7,
                    (void *)(VAR_LEN + 1 + VAR_LEN)
                }
            },
            {(void *)0, (void *)0}
		},
        NULL,
	};

    // initialize test
    init_test(&test, trys);

    // call each tests in test groups
    for (size_t j = 0; (size_t)trys[j]; j++)
    {
        for (size_t i = 0; (size_t)trys[j][i + 1].try; i++)
            tester(j, i + 1, &test);
    }

	// t_try	trys[] = {
	// 	{
	// 		.try = "",
	// 		.expected = "",
	// 	},
	// 	{
	// 		.try = "",
	// 		.expected = "",
	// 	},
	// } index kayiyo 1 tane aradan cikardinmi. index kayarsa kodun degismesi
	// gerekir. test caselerinin sayisina bagli olmamalidir kod.
    
}

void    init_test(t_test *test, t_try *trys[])
{
    size_t x;
    size_t y;

    for (x = 0; trys[x]; x++)
        ;
	test->tests = malloc(x * sizeof(void *));
    for (x = 0; trys[x]; x++)
    {
        for (y = 0; (size_t)trys[x][y + 1].try; y++)
            ;
        test->tests[x] = malloc(y * sizeof(t_tests));
    }

    for (size_t j = 0; (size_t)trys[j]; j++)
    {
        for (size_t i = 0; (size_t)trys[j][i + 1].try; i++)
        {
            test->tests[j][i].test_fun = ((t_fun *)trys[j][0].try)->test_fun;
            test->tests[j][i].ko_msg = ((t_fun *)trys[j][0].try)->ko_msg;
            test->tests[j][i].ok_msg = ((t_fun *)trys[j][0].try)->ok_msg;
            test->tests[j][i].name = trys[j][0].expected;
            test->tests[j][i].trys = trys[j] + i;
            printf("log ||||||| %s > %p [ %p | %p ]\n", (trys[j][0].expected), test->tests[j][i].test_fun, &complex_len_test, &expand_test);
        }
    }

	test->fails = NULL;
	test->success = NULL;
}

void	tester(int test_group_num, int test_number, t_test *test)
{
	int		result;

	test->test_number = test_number;
	test->test_group_num = test_group_num;
    test->current_test = test->tests[test_group_num] + test_number;
    (void)test->current_test->test_fun(test);
    printf("calistirici %d, %d\n", test_number, test_group_num);
	result = test->current_test->test_fun(test);
	if (result)
        test->current_test->ok_msg(test);
	else
	{
		ft_lstadd_back(&test->fails, ft_lstnew((void *)(size_t)(test_number)));
		test->current_test->ko_msg(test);
	}
}

void	run_test()
{
	all_tests();
	return ;
	// printf(BLUE"\n\n===================murminette====================\n");
	// printf(BLUE"=================================================\n"RESET);
	// printf(BLUE"=====================len_all=====================\n"RESET);
	// printf(BLUE"=================================================\n"RESET);

	// char    *str = "$$";
	// size_t  tmp;
	// size_t  _;
	// int  i = 0;
	// t_list *tm;
	// t_list *tm2;
	// size_t  dollar = 4;

	
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
	{"a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-3$-1$-2$=$11$30", "a$a0000=$-$$$$$$$-3$-1$-2$="},//çöz
	// {"\"a$a99-'$a\"", ""},
	// {"\"a$a99-'$a\"'$a$'\"a$a=$a99\"$-$'\"$'$'\"'$\"\"$\"$\"$-1$-=$11$$6","a-$a0000$a$a=$a99$-$$$$$$$-1$-="},
	{"123123'1\"12\"1130123'1\"12\"1130","1231231\"12\"11301231121130"},//çöz
	{"1'$a''$a'\"\"1\"\"\"$a\"''\"$a $a1\"","1$a$a100000000 "},//çöz
	// {"\"a'$'\"'a$a=$a99\'"$-$'$'$''$\"\"$\"$\"$-2$-=$11$$29","a'$'a$a=$a99$-$'$'$''$\"\"$\"$\"$-2$-=$11$$29"},
	// {"a\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-1$-2$-=$11$$17","aa0000=$a99$-$$$$$$$1$2$$11$$17"},


	{"a$\"a$a=$a99\"$-$'$'$''$\"\"$\"$\"$-$-$$-$$=11$$", "a$a0000=$-$$$$$$$-$-$$-$$=11$$", (void *)42, (void *)30},

//    '$a'"''$a''""'$a'""  '$a' $ $a ""  '$'  ""''"'"$a"'"$_"'$_'-=$$"$a"$''$$$-$'a'4"$a $a"a'$a''a'"v$a$av$"$' ''$'a'"$a"'"''"31
// my $a''0000'''0000'  '0000' $ 0000   '$'  ''"$a"./program$_-=$$0000$$$$-$a40000 0000a$aav0000$$ $a"$a"''31
// sh $a''0000'''0000'  '0000' $ 0000   '$'  ''"$a"./program$_-=$$0000$$$$-$a40000 0000a$aav0000$$ $a"$a"''31 oldu

//    $a''0000'''0000'

//    '"  $ $ $a "''$'""''"'"99"'""$_""'$_'-=$$"'$a'"$''$$$-$'a'4"'$a $'a"a'$a''a'"v$'a$'av$"$' ''$'a'"'$'a"'"''"31"
// my "  $ $ $a "$'99'./program'./program'-=$$$a$''$$$-$'a'4$a $aa'0000''a'v$a$av$$' ''$'a'$a'31
// sh "  $ $ $a "$'99'./program'./program'-=$$$a$''$$$-$'a'4$a $aa'0000''a'v$a$av$$' ''$'a'$a'31
	{"'$a'\"''$a''\"\"'$a'\"\"  '$a' $ $a \"\"  '$'  \"\"''\"'\"$a\"'\"$_\"'$_'-=$$\"$a\"$''$$$-$'a'4\"$a $a\"a'$a''a'\"v$a$av$\"$' ''$'a'\"$a\"'\"''\"31", \
	 "$a''0000'''0000'  '0000' $ 0000   '$'  ''\"$a\"./program$_-=$$0000$$$$-$a40000 0000a$aav0000$$ $a\"$a\"''31"},
	{"'\"  $ $ $a \"''$'\"\"''\"'\"99\"'\"\"$_\"\"'$_'-=$$\"'$a'\"$''$$$-$'a'4\"'$a $'a\"a'$a''a'\"v$'a$'av$\"$' ''$'a'\"'$'a\"'\"''\"31\"", \
	 "\"  $ $ $a \"$'99'./program'./program'-=$$$a$''$$$-$'a'4$a $aa'0000''a'v$a$av$$' ''$'a'$a'31"},

		{(void *)0, (void *)0}
	};

    
    
    
    
    
    
	// _ = 0;
	// t_main *data = malloc(sizeof(t_main));
	// // tmp = var_name_len("aaa");
	// // printf("var_name_len: %zu\n", tmp);
	// // printf("%d\n", (is_text(str[_]) && !((str[_] == '$') && is_var(str[_ + 1]))));
	// ft_bzero(data->increases, INT8_MAX);
	// data->increases['"'] = (char)2;
	// data->increases['\''] = (char)2;
	// data->increases[0] = (char)0;
	// data->vars = NULL;
	// set(data, strdup("a"), strdup("0000"));
	// t_list *root = NULL;
	// // ============================complex_len_test=============================
	// while (complex_len_tests[i][0])
	// {
	// 	data->line = complex_len_tests[i][0];
	// 	printf("line: %s\n", data->line);
	// 	if (len_all(data, 0) == (size_t)complex_len_tests[i][1])
	// 		printf("=================TEST %d=%s================\n", i, result[0]);
	// 	else
	// 	{
	// 		ft_lstadd_back(&root, ft_lstnew((void *)(size_t)i));
	// 		printf(YELLOW"expected %zu\n"RESET, (size_t)complex_len_tests[i][1]);
	// 		printf("^^^^^^^^=========TEST %d=%s================\n", i, result[1]);
	// 	}
	// 	i++;
	// }
	// printf(BLUE"\n\n=================================================\n"RESET);
	// printf(BLUE"==================dquote expand==================\n"RESET);
	// printf(BLUE"=================================================\n"RESET);
	// // ===============================expand_test===============================
	// i = 0;
	// size_t  *sonuc;
	// char    *buffer;
	// char     err = 0;
	// while (expand_tests[i][0])
	// {
	// 	data->line = expand_tests[i][0];
	// 	printf("[=====================TEST %d=====================]\n", i);
	// 	printf("    line: %s\n", data->line);
	// 	buffer = calloc(strlen(expand_tests[i][0]), 4);
	// 	sonuc = expander_exp(data, buffer, 0);
	// 	// printf("sonuc: %s\n", buffer);
	// 	if (strcmp(expand_tests[i][1], buffer))
	// 	{
	// 		err |= 0b00000001;
	// 		printf("⋁⋁⋁⋁⋁⋁⋁⋁--------------str-%s---------------------\n", result[1]);
	// 		printf(YELLOW"expected %s\n"RESET, expand_tests[i][1]);
	// 		printf(YELLOW"result %s\n"RESET, buffer);
	// 	}
	// 	else
	// 	{
	// 		printf("----------------------str-%s---------------------\n", result[0]);
	// 		printf(GREEN"expected %s\n"RESET, expand_tests[i][1]);
	// 		printf(GREEN"result %s\n"RESET, buffer);
	// 	}

	// 	if (sonuc[0] != (size_t)expand_tests[i][2])
	// 	{
	// 		err |= 0b00000010;
	// 		printf("⋁⋁⋁⋁⋁⋁⋁⋁----------len normal-%s------------------\n", result[1]);
	// 		printf(YELLOW"expected %zu\n"RESET, (size_t)expand_tests[i][2]);
	// 		printf(YELLOW"result %zu\n"RESET, sonuc[0]);
	// 	}
	// 	else
	// 	{
	// 		printf("-------------------len normal-%s-----------------\n", result[0]);
	// 		printf(GREEN"expected %zu\n"RESET, (size_t)expand_tests[i][2]);
	// 		printf(GREEN"result %zu\n"RESET, sonuc[0]);
	// 	}

	// 	if (sonuc[1] != (size_t)expand_tests[i][3])
	// 	{
	// 		err |= 0b00000100;
	// 		printf("⋁⋁⋁⋁⋁⋁⋁⋁--------len expanded-%s------------------\n", result[1]);
	// 		printf(YELLOW"expected %zu\n"RESET, (size_t)expand_tests[i][3]);
	// 		printf(YELLOW"result %zu\n"RESET, sonuc[1]);
	// 	}
	// 	else
	// 	{
	// 		printf("-----------------len expanded-%s-----------------\n", result[0]);
	// 		printf(GREEN"expected %zu\n"RESET, (size_t)expand_tests[i][3]);
	// 		printf(GREEN"result %zu\n"RESET, sonuc[1]);
	// 	}
	// 	printf("[===================TEST %d=%s==================]\n\n\n\n", i, result[0 || err]);

	// 	free(sonuc);
	// 	free(buffer);
	// 	i++;
	// 	err = 0;
	// }

	// printf(BLUE"==================================================\n"RESET);
	// printf(BLUE"=====================Join ALL=====================\n"RESET);
	// printf(BLUE"==================================================\n\n\n"RESET);

	// i = 0;
	// while (mix[i][0])
	// {
	// 	data->line = mix[i][0];
	// 	printf("[=====================TEST %d=====================]\n", i);
	// 	printf("    line: %s\n", data->line);
	// 	// buffer = calloc(strlen(mix[i][0]), 4);
	// 	buffer = join_all(data, 0).buffer;
	// 	// printf("sonuc: %s\n", buffer);
	// 	if (strcmp(mix[i][1], buffer))
	// 	{
	// 		err |= 0b00000001;
	// 		printf("⋁⋁⋁⋁⋁⋁⋁⋁--------------str-%s---------------------\n", result[1]);
	// 		printf(YELLOW"expected %s\n"RESET, mix[i][1]);
	// 		printf(YELLOW"result %s\n"RESET, buffer);
	// 	}
	// 	else
	// 	{
	// 		printf("----------------------str-%s---------------------\n", result[0]);
	// 		printf(GREEN"expected %s\n"RESET, mix[i][1]);
	// 		printf(GREEN"result %s\n"RESET, buffer);
	// 	}

	// 	// if (sonuc[0] != (size_t)expand_tests[i][2])
	// 	// {
	// 	//     err |= 0b00000010;
	// 	//     printf("⋁⋁⋁⋁⋁⋁⋁⋁----------len normal-%s------------------\n", result[1]);
	// 	//     printf(YELLOW"expected %zu\n"RESET, (size_t)expand_tests[i][2]);
	// 	//     printf(YELLOW"result %zu\n"RESET, sonuc[0]);
	// 	// }
	// 	// else
	// 	// {
	// 	//     printf("-------------------len normal-%s-----------------\n", result[0]);
	// 	//     printf(GREEN"expected %zu\n"RESET, (size_t)expand_tests[i][2]);
	// 	//     printf(GREEN"result %zu\n"RESET, sonuc[0]);
	// 	// }

	// 	// if (sonuc[1] != (size_t)expand_tests[i][3])
	// 	// {
	// 	//     err |= 0b00000100;
	// 	//     printf("⋁⋁⋁⋁⋁⋁⋁⋁--------len expanded-%s------------------\n", result[1]);
	// 	//     printf(YELLOW"expected %zu\n"RESET, (size_t)expand_tests[i][3]);
	// 	//     printf(YELLOW"result %zu\n"RESET, sonuc[1]);
	// 	// }
	// 	// else
	// 	// {
	// 	//     printf("-----------------len expanded-%s-----------------\n", result[0]);
	// 	//     printf(GREEN"expected %zu\n"RESET, (size_t)expand_tests[i][3]);
	// 	//     printf(GREEN"result %zu\n"RESET, sonuc[1]);
	// 	// }
	// 	printf("[===================TEST %d=%s==================]\n\n\n\n", i, result[0 || err]);

	// 	// free(sonuc);
	// 	free(buffer);
	// 	i++;
	// 	err = 0;
	// }

	// tm = root;
	// printf(BLUE"=============================================\n"RESET);
	// printf(BLUE"==================SUMMARY====================\n"RESET);
	// // print error tests.
	// while (root)
	// {
	// 	printf(YELLOW"error test: %zu"RESET, (size_t)(root->content));
	// 	if (root->next)
	// 		printf(", ");
	// 	else
	// 		printf("\n");
	// 	root = root->next;
	// }
	// // clear lst
	// while (tm)
	// {
	// 	tm2 = tm;
	// 	tm = tm->next;
	// 	free(tm2);
	// }
	// free(data);
	// // make leak for fsanitize=address
	// // tm = 0;
	// // tm2 = 0;
	
	// printf(BLUE"=============================================\n"RESET);
	// printf(BLUE"=============================================\n"RESET);
}
