#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	ft_free(char *s);
size_t	ft_strlen(const char *s);
int		check_line(char *s);
void	ft_parse(char **leftover, char *buf, int fd, int *ret);
int		get_next_line(int fd, char **line);

#endif