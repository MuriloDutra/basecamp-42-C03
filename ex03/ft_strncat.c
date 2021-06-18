#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char dest[7] = "123";
	char src[4] = "456";
	int nb = 2;
	
	printf("src: %s\ndest: %s\nnb: %d\n", src, dest, nb);
	printf("strncat: %s | ", strncat(dest, src, nb));

	// Re-sets the strings
	strcpy(dest, "123");
	strcpy(src, "456");

	printf("ft_strncat: %s \n", ft_strncat(dest, src, nb));
}

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	counter;
	unsigned int	dest_length;
	unsigned int	src_length;

	dest_length = ft_strlen(dest) - 1;
	src_length = ft_strlen(src) - 1;
	counter = dest_length;
	while (counter <= (dest_length + src_length))
	{
		counter++;
		if(counter - (dest_length + 1) < nb)
			dest[counter] = src[counter - (dest_length + 1)];
	}
	dest[counter + 1] = '\0';
	return (dest);
}
