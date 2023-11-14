#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static void     printer(char *str, char *new, char c)
{
        while (c < 127)
	{
		int i = -1;
		printf("\033[H\033[J");
		memset(new, c, strlen(str));
		while (++i < strlen(str))
			if (c > str[i])
				new[i] = str[i];
		printf("%s\n", new);
		usleep(100000);
        	if (strcmp(new, str) == 0)
                	return ;
		c++;
	}
}

static char    *argvs_concatenator(int argc, char **argv)
{
        char    *concatened;
        int     count = 0;
        int     total_size = 0;

        while (++count < argc)
        {
                total_size += strlen(argv[count]) + 1;
                concatened = (char*)malloc(total_size);
        }
        if (concatened == NULL)
                return NULL;
        concatened[0] = '\0';
        count = 0;
        while (++count < argc)
        {
                strcat(concatened, argv[count]);
                strcat(concatened, " ");
        }
        concatened[strlen(concatened)] = '\0';
        return (concatened);
}

int     main(int argc, char **argv)
{
        char    *str;

        if (argc < 2)
                return (0);
        if (argc > 2)
                str = argvs_concatenator(argc, argv);
        else
                str = argv[1];
        char    new[strlen(str) + 1];

        new[strlen(str)] = '\0';
        printer(str, new, ' ');
        return (0);
}
