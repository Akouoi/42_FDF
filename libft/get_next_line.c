/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:52:38 by akouoi            #+#    #+#             */
/*   Updated: 2022/08/09 17:31:39 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*supercat(char *dest, char *src, size_t lu)
{
	size_t	i;
	size_t	j;

	j = ft_n_strlen(dest);
	i = 0;
	while (i < lu && src[i] && src[i] != '\n')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	if (src[i] == '\n')
		dest[j++] = src[i];
	dest[j] = '\0';
	return (dest);
}

char	*superjoin(char *s1, char *s2)
{
	char	*strjoin;

	strjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strjoin)
		return (NULL);
	ft_strlcpy(strjoin, s1, ft_n_strlen(s1) + 1);
	supercat(strjoin, s2, ft_n_strlen(s2));
	free (s1);
	return (strjoin);
}

char	*free_return(char *line, int lu, char *tmp)
{
	if (!lu && *line)
		return (line);
	if (!lu && !ft_strchr(tmp, '\n'))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_line(char *line, char *tmp, int fd, int lu)
{
	while (lu)
	{
		lu = read(fd, tmp, BUFFER_SIZE);
		tmp[lu] = '\0';
		line = superjoin(line, tmp);
		if (ft_strchr(tmp, '\n'))
		{
			ft_strlcpy(tmp, ft_strchr(tmp, '\n') + 1, BUFFER_SIZE);
			break ;
		}
	}
	return (free_return(line, lu, tmp));
}

char	*get_next_line(int fd)
{
	static char	tmp[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			lu;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, tmp[fd], 0) == -1)
		return (NULL);
	lu = 1;
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	*line = '\0';
	if (ft_strchr(tmp[fd], '\n'))
	{
		line = superjoin(line, tmp[fd]);
		ft_strlcpy(tmp[fd], ft_strchr(tmp[fd], '\n') + 1, BUFFER_SIZE);
		return (free_return(line, lu, tmp[fd]));
	}
	if (tmp[fd])
		ft_strlcpy(line, tmp[fd], BUFFER_SIZE);
	return (ft_line(line, tmp[fd], fd, lu));
}

	// printf("coucou\n");
// int	main(int ac, char **av)
// {
// 	int fd;
// 	char *str;
// 	int i=0;
// 	int f=2;
// 	while(f < ac)
// 	{
// 		fd = open(av[f], O_RDONLY);
// 		while (i < atoi(av[1]))
// 		{
// 			str = get_next_line(fd);
// 			printf("gnl [%d] :%s", i, str);
// 			free(str);
// 			i++;
// 		}
// 		close (fd);
// 		return (0);
// 	}
// }