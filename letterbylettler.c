#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static char	*printer(char *str, char *new, int position)
{
	int	i = '\0';

	str++;
	while (i <= *str)
	{
		usleep(10000);
		if (i == 1)
			i = ' ';
		if (i != '\0')
			printf("%s%c\n", new, i);
		usleep(10000);
		printf("\033[H\033[J");
		i++;
	}
	new[position] = i - 1;
	if (new[position] == '\0')
		return (new);
	printer(str, new, position + 1);
	return (0);
}

static void	print_first_letter(char *str)
{
	char	new[strlen(str)];
        int	max = strlen(str);
        int	i = '\0';

	while (max--)
		new[max] = 0;
	while (i <= *str)
	{
		usleep(10000);
		if (i == 1)
			i = ' ';
		if (i != '\0')
			printf("%c\n", i);
		usleep(10000);
		printf("\033[H\033[J");
		i++;
	}
	new[0] = i - 1;
	printer(str, new, 1);
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
        concatened[strlen(concatened) - 1] = '\0';
        return (concatened);
}

int	main(int argc, char **argv)
{
	char	*str;

	if (argc < 2)
		return (0);
	if (argc > 2)
		str = argvs_concatenator(argc, argv);
	else
		str = argv[1];
	print_first_letter(str);
	printf("%s\n", str);
	return (0);
}
