#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int result;

	result = 0;

	while (*str)
	{
		result++;
		str++;
	}
	return result;
}

int	main(void)
{
	char my_string[] = "hello";

	printf("%d", ft_strlen(my_string));
}
