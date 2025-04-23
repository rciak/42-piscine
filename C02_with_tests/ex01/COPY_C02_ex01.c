#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(int argc, char **argv)
{	
	char			copy[6 + 1];
	char			copy_with_too_less_mem[5];
	char			*ori;
	unsigned int	n;

	if (argc != 1 +1)
	{
		fprintf(stderr, "Wrong number of arguments. (Expected: 1)");
		return (1);
	}
	n = atoi(argv[1]);
	ori="Hello!";
	printf("ori: %p |%s|\n", ori, ori);
	printf("--------------------------------------------\n");
	printf("calling ft_strncpy(copy, ori, n)\n");
	ft_strncpy(copy, ori, n);
	printf("   ori:  %p |%s|\n", ori, ori);
	printf("   copy: %p |%s|\n", copy, copy);
	printf("--------------------------------------------\n");
	printf("calling ft_strncpy(copy_with_too_less_mem, ori)\n");
	ft_strncpy(copy_with_too_less_mem, ori, n);
	printf("   ori:                    %p |%s|\n", ori, ori);
	printf("   copy:                   %p |%s|\n", copy, copy);
	printf("   copy_with_too_less_mem: %p |%s|\n", copy_with_too_less_mem, copy_with_too_less_mem);
}
