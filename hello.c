#include <stdio.h>
#include <unistd.h>

static int	strsize(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
		i++;
	}
	new[position] = i - 1;
	if (new[position] == '\0')
		return (new);
	printer(str, new, position + 1);
}

static void	first_letter(char *str)
{
	char	new[strsize(str)];
        int	max = strsize(str);
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
		i++;
	}
	new[0] = i - 1;
	printer(str, new, 1);
}

int	main(int argc, char **argv)
{
	char	*str;
        int	n = 1;
        int	c = argc;

	(void)argc;
	while (n < c)
	{
		str = argv[n];
		first_letter(str);
		n++;
	}
	return (0);
}
