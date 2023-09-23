#include "include.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



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

	i = 0;
	a = stacks->stack_a;
	b = stacks->stack_b;
	if (stacks->stack_a || stacks->stack_b)
	{
		p(" ___________ 	 ___________\n");
		p("|           |	|           |\n");
		while (a || b)
		{
			if (a)
			{
				p("| ");
				x = p("%d", a[0]);
				if (x <= 5)
					p("	    |");
				else if (x == 6)
					p("    |");
				else if (x == 7)
					p("   |");
				else if (x == 8)
					p("  |");
				else if (x == 9)
					p(" |");
				else if (x == 10)
					p("|");
				a = a[1];
			}
			else
				p("-");
			if (b)
			{
				p("	| ");
				x = p("%d", b[0]);
				if (x <= 5)
				{
					p("	    |");
				}
				else if (x == 6)
				{
					p("    |");
				}
				else if (x == 7)
				{
					p("   |");
				}
				else if (x == 8)
				{
					p("  |");
				}
				else if (x == 9)
				{
					p(" |");
				}
				else if (x == 10)
				{
					p("|");
				}
				p("\n");
				b = b[1];
			}
			else
				p("	|     -     |\n");
			i++;
			// p("---------------------------\n");
		}
		p("|___________|	|___________|\n");
		p("      a  	      b   \n");
	}
	return (i);
}

void	print_links(void *iter, void *data)
{
	t_link a;
	t_link b;

	a = (t_link)iter;
	b = (t_link)data;
	while (a || b)
	{
		char *template;
		char *tmp;

		tmp = callocate(91, 1);
		template = callocate(91, 1);
		xmemset(template, ' ', 91);

		(void)b;
		sprintf(tmp, "v: %d", (int)((t_link)a)[0]);
		xstrlcpy(template, tmp, 15);
		// p("{%s}", template);
		xmemset(tmp, '\0', 80);
		if (((t_link)(((t_link)a)[1])))
		{
			sprintf(tmp, "n: %d", (int)((t_link)(((t_link)a)[1]))[0]);
			xstrlcpy(template + 15, tmp, 15);
			xmemset(tmp, '\0', 80);
		}
		else
		{
			sprintf(tmp, "n: %d", 0);
			xstrlcpy(template + 15, tmp, 15);
			xmemset(tmp, '\0', 80);
		}

		if (((t_link)(((t_link)a)[2])))
		{
			sprintf(tmp, "p: %d", (int)((t_link)(((t_link)a)[2]))[0]);
			xstrlcpy(template + 15 + 15, tmp, 15);
			xmemset(tmp, '\0', 80);
		}
		else
		{
			sprintf(tmp, "p: %d", 0);
			xstrlcpy(template + 15 + 15, tmp, 15);
			xmemset(tmp, '\0', 80);
		}

        if (((t_link)b))
		{
			sprintf(tmp, "\t|\tv: %d, ", (int)((t_link)b)[0]);
			xstrlcpy(template + 15 + 15 + 15, tmp, 18);
			xmemset(tmp, '\0', 80);
		}
        else
        {
            sprintf(tmp, "\t|\tv: %d, ", 0);
			xstrlcpy(template + 15 + 15 + 15, tmp, 18);
			xmemset(tmp, '\0', 80);
        }
		
		if (((t_link)b) && ((t_link)(((t_link)b)[1])))
		{
			sprintf(tmp, "n: %d, ", (int)((t_link)(((t_link)b)[1]))[0]);
			xstrlcpy(template + 15 + 15 + 15 + 18, tmp, 15);
			xmemset(tmp, '\0', 80);
		}
		else
		{
			sprintf(tmp, "n: %d, ", 0);
			xstrlcpy(template + 15 + 15 + 15 + 18, tmp, 15);
			xmemset(tmp, '\0', 80);
		}
		if (((t_link)b) && ((t_link)(((t_link)b)[2])))
		{
			sprintf(tmp, "p: %d", (int)((t_link)(((t_link)b)[2]))[0]);
			xstrlcpy(template + 15 + 15 + 15 + 18 + 15, tmp, 15);
			xmemset(tmp, '\0', 80);
		}
		else
		{
			sprintf(tmp, "p: %d", 0);
			xstrlcpy(template + 15 + 15 + 15 + 18 + 15, tmp, 15);
			xmemset(tmp, '\0', 80);
		}
		p("%s\n", template);
		free(tmp);
		free(template);
        if (a)
            a = a[1];
        if (b)
            b = b[1];
	}
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

    // appendRandomNumbersToFile("./ast", 235468/3);

    while (str)
    {
        lp_add(&lines, lp_new(str));
        str = multi_get_line(fd);
    }
    str = callocate(sizeof(char *), 1 + lp_len(lines));
    lp_iter(lines, 0, iter1, str);
    ((char **)str)[lp_len(lines)] = 0;
    while (lines)
        lp_pop(&lines, del);
    close(fd);
    return ((char **)str);
}