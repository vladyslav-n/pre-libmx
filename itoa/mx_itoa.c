#include "../inc/libmx.h"

short int numlen(int n)
{
	int len = 1;
	int nbr = n;
	while (nbr /= 10)
		len += 1;
	return len;
}

char *mx_itoa(int number)
{
	if (number == -2147483648)
	{
		return "-2147483648";
	}
	int n = number;
	int len = numlen(n);
	if (number < 0)
	{
		len += 1;
		n = -n;
	}
    #ifdef DEBUG
        printf("len = %d\n", len);
    #endif

	char *str = (char*) malloc(sizeof(char) * (len + 1));
	str[len] = 0;
	if (number < 0)
	{
		for (int i = 1; i < len; i++)
		{	
			str[len - i] = n % 10 + '0';
			n /= 10;
		}
		str[0] = '-';
	}
	else 
	{
		for (int i = 0; i < len; i++)
		{	
			str[len - 1 - i] = n % 10 + '0';
			n /= 10;
		}
	}
	#ifdef DEBUG
		printf("%s\n", str);
	#endif
	return str;
}

