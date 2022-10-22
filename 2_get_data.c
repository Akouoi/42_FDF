/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_get_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:10:44 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/16 09:07:18 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_atoi(const char *str)
{
	int				sign;
	int				i;
	long long int	result;

	i = 0;
	result = 0;
	sign = 1 - 2 * (str[i] == '-');
	if (str[i] == '+' || str[i] == '-')
			i++;
	if (str[i] < '0' || str[i] > '9')
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result *= sign;
	return (result > 2147483647 || result < -2147483648);
}

int	check_number(char *str)
{
	int	i;

	i = 1;
	if (ft_strlen(str + (str[0] == '-')) > 11)
		return (1);
	if (!(ft_isdigit(str[0]) || (str[0] == '-')))
	{
		return (1);
	}
	if (str[0] == '-' && !ft_isdigit(str[1]))
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !(str[i] == 'x') && !(str[i] == ','))
			return (1);
		i++;
	}
	if (check_atoi(str) == 1)
		return (1);
	return (0);
}

int	check_arg(char *str, t_data *data)
{
	int		i;
	char	**tab;

	i = -1;
	if (str && data->lx != 0 && data->lx != ft_w_nbr(str, ' '))
		return (write(2, "Wrong_line length\t->", 15));
	data->lx = ft_w_nbr(str, ' ');
	tab = ft_split(str, ' ');
	while (tab[++i])
	{
		if (check_number(tab[i]) == 1)
		{
			ft_clear(tab);
			return (write(2, "Not an int \t->", 15));
		}
	}
	ft_clear(tab);
	return (0);
}

int	get_data(t_data *data, char **av)
{
	int		fd;
	char	*str;

	if (av[1][0] == '/' || ft_inter("maps/", av[1], 5) == 5)
		data->file = ft_strdup(av[1]);
	else
		data->file = ft_strjoin("maps/", av[1]);
	fd = open(data->file, O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (str[ft_strlen(str) - 1] == '\n')
			str[ft_strlen(str) - 1] = '\0';
		if (check_arg(str, data) == 15)
			return (free(str), close(fd), 1);
		ft_lstadd_back(data->lst, ft_lstnew(str));
		data->ly++;
	}
	return (close(fd), 0);
}
