#include "../../inc/minirt.h"

int	get_file_fd(char *s)
{
	int	i;
	int	fd;

	if(ft_strncmp(s, "scenes/", 7))
		return (-2);
	i = ft_strlen(s) -1;
	if(s[i] != 't' && s[i] != 'r' && s[i] != '.')
		return (-2);
	fd = open(s, O_RDONLY, 0644);
	return (fd);
}
