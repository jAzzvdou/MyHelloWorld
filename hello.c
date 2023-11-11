#include <stdio.h>

static int	strsize(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	printer(char *str, char *new, int position)
{
	int	i = '\0';
	int	timer = 0;

	str++;
	while (i <= *str)
	{
		if (timer == 10000000)
		{
			if (i == 1)
				i = ' ';
			if (i != '\0')
				printf("%s%c\n", new, i);
			timer = 0;
			i++;
		}
		timer++;
	}
	new[position] = i - 1;
	if (new[position] == '\0')
		return ;
	printer(str, new, position + 1);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	char	*str = argv[1];
	char	new[strsize(str)];
	int	max = strsize(str);
	int	timer = 0;
	int	i = '\0';

	while (max--)
		new[max] = 0;
	while (i <= *str)
	{
		if (timer == 10000000)
		{
			if (i == 1)
				i = ' ';
			if (i != '\0')
				printf("%c\n", i);
			timer = 0;
			i++;
		}
		timer++;
	}
	new[0] = i - 1;
	printer(str, new, 1);
}
