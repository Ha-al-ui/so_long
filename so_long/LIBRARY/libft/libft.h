#ifndef LIBRARY_H
# define LIBRARY_H

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *s);
void	ft_error(char *str);
int	    ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

char	*get_next_line(int fd);

#endif