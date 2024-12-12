#include "testing.h"

int isDuplicate(int *array, int size, int number) {
	for (int i = 0; i < size; ++i) {
		if (array[i] == number) {
			return 1;
		}
	}
	return 0;
}

void appendRandomNumbersToFile(const char *filePath, int numberOfRandomNumbers) {
	FILE *file = fopen(filePath, "a");
	if (file == NULL) {
		printf("Dosya açılamadı.\n");
		return;
	}

	srand(time(0));

	int *generatedNumbers = (int *)malloc(numberOfRandomNumbers * sizeof(int));
	if (generatedNumbers == NULL) {
		printf("Bellek hatası\n");
		fclose(file);
		return;
	}

	int generatedCount = 0;

	while (generatedCount < numberOfRandomNumbers) {
		int randomNumber = rand();
		if (!isDuplicate(generatedNumbers, generatedCount, randomNumber)) {
			generatedNumbers[generatedCount] = randomNumber;
			generatedCount++;
		}
	}
	printf("writing.\n");
	fflush(stdout);
	for (int i = 0; i < numberOfRandomNumbers; ++i) {
		fprintf(file, "%d\n", generatedNumbers[i]);
	}

	free(generatedNumbers);
	fclose(file);
	printf("Rastgele sayılar dosyaya eklendi.\n");
}



int	print_stacks(t_stacks *stacks)
{
	int		i;
	int		x;
	t_link	a;
	t_link	b;
	int		ct;

	ct = 0;
	i = 0;
	a = stacks->stack_a;
	b = stacks->stack_b;
    p("\na: %d		b: %d\n", lp_len(stacks->stack_a), lp_len(stacks->stack_b));
	if (stacks->stack_a || stacks->stack_b)
	{
		p("\033[1;34m ___________\033[0m 	 \033[1;31m___________\033[0m\n");
		p("\033[1;34m|           |\033[0m	\033[1;31m|           |\033[0m\n");
		while (a || b)
		{
			if (a)
			{
				p("\033[1;34m| ");
				x = p("%d", a[0]);
				if (x <= 5)
					p("	    |\033[0m");
				else if (x == 6)
					p("    |\033[0m");
				else if (x == 7)
					p("   |\033[0m");
				else if (x == 8)
					p("  |\033[0m");
				else if (x == 9)
					p(" |\033[0m");
				else if (x == 10)
					p("|\033[0m");
				a = a[1];
			}
			else
				p("|     -     |");
			if (b)
			{
				p("	\033[1;31m| ");
				x = p("%d", b[0]);
				if (x <= 5)
				{
					p("	    |\033[0m");
				}
				else if (x == 6)
				{
					p("    |\033[0m");
				}
				else if (x == 7)
				{
					p("   |\033[0m");
				}
				else if (x == 8)
				{
					p("  |\033[0m");
				}
				else if (x == 9)
				{
					p(" |\033[0m");
				}
				else if (x == 10)
				{
					p("|\033[0m");
				}
				p(" %d\n\033[0m", ct++);
				b = b[1];
			}
			else
				p("	|     -     | %d\n", ct++);
			i++;
			// p("---------------------------\n");
		}
		p("\033[1;34m|___________|\033[0m	\033[1;31m|___________|\n");
		p("      \033[1;34ma\033[0m  	      \033[1;31mb\033[0m   \n");
	}
	return (i);
}

void	print_links(void *iter, void *data)
{
	t_link a;
	t_link b;
	int	offset1;
	int	offset2;

	offset1 = 22;
	offset2 = 29;
	a = (t_link)iter;
	b = (t_link)data;
	p("\n		a: %d							b: %d\n", lp_len(iter), lp_len(data));
	p("===================================================================================================\n");
	p("===================================================================================================\n");
	while (a || b)
	{
		char	*template;
		char	*tmp;
		int		miktar;

		miktar = 110;
		tmp = callocate(miktar, 1);
		template = callocate(miktar, 1);
		xmemset(template, ' ', miktar);

		(void)b;
		sprintf(tmp, "\033[1;34mv: %d", (int)((t_link)a)[0]);
		xstrlcpy(template, tmp, offset1);
		// p("{%s}", template);
		xmemset(tmp, '\0', miktar);
		if (((t_link)(((t_link)a)[1])))
		{
			sprintf(tmp, "n: %d", (int)((t_link)(((t_link)a)[1]))[0]);
			xstrlcpy(template + offset1, tmp, 15);
			xmemset(tmp, '\0', miktar);
		}
		else
		{
			sprintf(tmp, "n: %d", 0);
			xstrlcpy(template + offset1, tmp, 15);
			xmemset(tmp, '\0', miktar);
		}

		if (((t_link)(((t_link)a)[2])))
		{
			sprintf(tmp, "p: %d", (int)((t_link)(((t_link)a)[2]))[0]);
			xstrlcpy(template + offset1 + 15, tmp, 15);
			xmemset(tmp, '\0', miktar);
		}
		else
		{
			sprintf(tmp, "p: %d", 0);
			xstrlcpy(template + offset1 + 15, tmp, 15);
			xmemset(tmp, '\0', miktar);
		}

		if (((t_link)b))
		{
			sprintf(tmp, "\t|\033[0m\t\033[1;31mv: %d ", (int)((t_link)b)[0]);
			xstrlcpy(template + offset1 + 15 + 15, tmp, offset2);
			xmemset(tmp, '\0', miktar);
		}
		else
		{
			sprintf(tmp, "\t|\033[0m\t\033[1;31mv: %d ", 0);
			xstrlcpy(template + offset1 + 15 + 15, tmp, offset2);
			xmemset(tmp, '\0', miktar);
		}
		
		if (((t_link)b) && ((t_link)(((t_link)b)[1])))
		{
			sprintf(tmp, "n: %d ", (int)((t_link)(((t_link)b)[1]))[0]);
			xstrlcpy(template + offset1 + 15 + 15 + offset2, tmp, 15);
			xmemset(tmp, '\0', miktar);
		}
		else
		{
			sprintf(tmp, "n: %d ", 0);
			xstrlcpy(template + offset1 + 15 + 15 + offset2, tmp, 15);
			xmemset(tmp, '\0', miktar);
		}
		if (((t_link)b) && ((t_link)(((t_link)b)[2])))
		{
			sprintf(tmp, "p: %d", (int)((t_link)(((t_link)b)[2]))[0]);
			xstrlcpy(template + offset1 + 15 + 15 + offset2 + 15, tmp, 15);
			xmemset(tmp, '\0', miktar);
		}
		else
		{
			sprintf(tmp, "p: %d", 0);
			xstrlcpy(template + offset1 + 15 + 15 + offset2 + 15, tmp, 15);
			xmemset(tmp, '\0', miktar);
		}
		p("%s\033[0m\n", template);
		free(tmp);
		free(template);
		if (a)
			a = a[1];
		if (b)
			b = b[1];
	}
	p("===================================================================================================\n");
	p("===================================================================================================\n");
}

static void iter1(void *iter, int index, void *data)
{
	(void)index;
	(void)iter;
	(void)data;
	((char **)data)[index] = ((t_link)iter)[0];
}

int     tablen(char **tab)
{
	size_t	c;

	c = 0;
	while (tab[c])
		c++;
	return (c);
}

char    **file_load(char *path)
{
	int     fd;
	char    *str;
	t_link  lines;

	lines = NULL;
	fd = open(path, 600, O_RDONLY);
	str = multi_get_line(fd);
	str[xstrlen(str)-1] = 0;

	// appendRandomNumbersToFile("./ast", 235468/3);

	while (str)
	{
		lp_add(&lines, lp_new(str));
		str = multi_get_line(fd);
		if (str)
		str[xstrlen(str)-1] = 0;
	}
	str = callocate(sizeof(char *), 1 + lp_len(lines));
	lp_iter(lines, 0, iter1, str);
	((char **)str)[lp_len(lines)] = 0;
	while (lines)
		lp_pop(&lines, del);
	close(fd);
	return ((char **)str);
}