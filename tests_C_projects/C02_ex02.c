#include <stdio.h>

int		ft_str_is_alpha(char *str);

int	main(int argc, char **argv)
{	
	int	result;

	if (argc != 1 +1)
	{
		fprintf(stderr, "Wrong number of arguments. (Expected: 1)");
		return (1);
	}
	result = ft_str_is_alpha(argv[1]);
	printf("argv[1]          : |%s|\n", argv[1]);
	printf("ft_str_is_alspha : %d\n", result);
}