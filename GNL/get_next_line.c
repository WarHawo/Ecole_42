#include "get_next_line.h"

int		check_line(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_parse(char **leftover, char *buf, int fd, int *ret)
{
	while (check_line(*leftover) == -1 && (*ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*ret] = '\0';
		*leftover = ft_strjoin(*leftover, buf);
	}
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*leftover = NULL;
	char		*temp;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	ft_parse(&leftover, buf, fd, &ret);
	if (check_line(leftover) > -1)
	{
		*line = ft_substr(leftover, 0, check_line(leftover));
		temp = ft_substr(leftover, check_line(leftover) + 1,
		ft_strlen(leftover));
		ft_free(leftover);
		leftover = ft_substr(temp, 0, ft_strlen(temp));
		ft_free(temp);
		return (1);
	}
	else
	{
		*line = ft_substr(leftover, 0, ft_strlen(leftover));
		ft_free(leftover);
	}
	return (0);
}