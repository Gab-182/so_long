#include "so_long.h"

char	*ft_strrchr(char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	while (n >= 0)
	{
		if (s[n] == (char)c)
		{
			return ((char *)&s[n]);
		}
		n--;
	}
	return (0);
}

/*-----------------------------------------------------------------------*/
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

/*-----------------------------------------------------------------------*/