#include "cub3d.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*join;
	int		i;
	int		j;

	len = 0;
	if (s1 != NULL)
		len += ft_strlen(s1);
	if (s2 != NULL)
		len += ft_strlen(s2);
	if (!(join = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

char	*ft_strdup(const char *src)
{
	char	*p;
	size_t	len;
	int		k;

	len = ft_strlen((char *)src);
	if (!(p = (char *)malloc(len + 1)))
		return (NULL);
	k = 0;
	while (src[k] != '\0')
	{
		p[k] = src[k];
		k++;
	}
	p[k] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	len_true;
	size_t	i;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		len_true = 0;
	else
		len_true = ((len <= (len_s - start)) ? len : (len_s - start));
	if (!(sub = (char *)malloc(len_true + 1)))
		return (NULL);
	i = 0;
	while (len_true > 0)
	{
		sub[i++] = s[start++];
		len_true--;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str_s;
	char	char_c;

	str_s = (char *)s;
	char_c = (char)c;
	if (c == '\0')
	{
		while (*str_s)
			str_s++;
		return (str_s);
	}
	else
	{
		while (*str_s)
			if (*str_s++ == char_c)
				return (--str_s);
	}
	return (NULL);
}
