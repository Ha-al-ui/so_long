#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	strl_len;
	char			*p;

	if (!s)
		return (NULL);
	strl_len = ft_strlen(s);
	i = 0;
	if (start > strl_len)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
