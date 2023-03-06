#include "lib.h"

size_t	ft_strlen(const char *str)
{
	size_t	cont;

	cont = 0;
	while (*(str) != '\0')
	{
		cont++;
		str = str + 1;
	}
	return (cont);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		i;
	size_t	ptrs1;

	i = 0;
	ptrs1 = ft_strlen((char *)s1);
	ptr = (char *)malloc(ptrs1 + 1 + 1);
	if (!ptr)
		return (NULL);
	while (i <= (int)ptrs1)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}

int	len(long m)
{
	int	lens;

	lens = 0;
	if (m <= 0)
		lens = 1;
	while (m != 0)
	{
		lens++;
		m = m / 10;
	}
	return (lens);
}

char	*ft_itoa(int n)
{
	char	*s;
	int	i;
	long	m;

	m = n;
	i = len(m);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i--] = '\0';
	if (m == 0)
		s[0] = '0';
	if (m < 0 )
	{
		s[0] = '-';
		m = m * -1;
	}
	while (m > 0)
	{
		s[i] = '0' + (m % 10);
		m = m / 10;
		i--;
	}
	return (s);
}