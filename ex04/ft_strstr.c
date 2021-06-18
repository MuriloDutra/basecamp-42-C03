#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char *str;
	char *to_find;
	char *buff;
	char *ft_buff;

	str = strcpy(calloc(11, sizeof(char)), "alo galera");
	to_find = strcpy(calloc(7, sizeof(char)), "galera");
	buff = strstr(str, to_find);
	ft_buff = ft_strstr(str, to_find);
	if (buff != ft_buff)
		printf("[1] KO, substrings don't match(expected:%s, got:%s)\n", buff, ft_buff); 
	else
		printf("[1] OK. expected: %s result: %s\n", buff, ft_buff);
	str = strcpy(calloc(11, sizeof(char)), "alo galera");
	to_find = strcpy(calloc(7, sizeof(char)), "galerA");
	buff = strstr(str, to_find);
	ft_buff = ft_strstr(str, to_find);
	if (buff != ft_buff)
		printf("[2] KO, substrings don't match(expected:%s, got:%s)\n", buff, ft_buff); 
	else
		printf("[2] OK. expected: %s result: %s\n", buff, ft_buff);
	str = strcpy(calloc(11, sizeof(char)), "alo galera");
	to_find = strcpy(calloc(1, sizeof(char)), "");
	buff = strstr(str, to_find);
	ft_buff = ft_strstr(str, to_find);
	if (buff != ft_buff)
		printf("[3] KO, substrings don't match(expected:%s, got:%s)\n", buff, ft_buff); 
	else
		printf("[3] OK. expected: %s result: %s\n", buff, ft_buff);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		c;
	int		sub_c;
	char	find_char;
	char	str_char;

	c = 0;
	while (str[c])
	{
		if (to_find[0] == str[c])
		{
			sub_c = 0;
			find_char = to_find[sub_c];
			str_char = str[c + sub_c];
			while(find_char == str_char
				&& find_char != '\0'
				&& ((find_char >= 'a' && <= 'z' && str_char >= 'a' && <= 'z')))
			{
				// printf("to_find[sub_c]: %c ", to_find[sub_c]);
				// printf("str[c + sub_c]: %c\n", str[c + sub_c]);
				sub_c++;
			}
			//printf("\n");
			if(to_find[sub_c] == '\0')
				return (&str[c]);
		}
		c++;
	}
	return to_find;
}

(to_find[sub_c] >= 'a' && <= 'z' && str_char >= 'a' && <= 'z')
(to_find[sub_c] >= 'A' && <= 'Z' && str_char >= 'A' && <= 'Z')