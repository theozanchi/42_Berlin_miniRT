#include "../../inc/minirt.h"

int	get_file_fd(char *s)
{
	int	i;
	int	fd;

	if (s == NULL || ft_strlen(s) == 0)
		return (-2);
	i = ft_strlen(s) -1;
	if(s[i] != 't' || s[i -1] != 'r' || s[i -2] != '.')
		return (-2);
	fd = open(s, O_RDONLY, 0644);
	return (fd);
}
