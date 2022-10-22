/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:52:09 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/06 13:49:58 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
}
/*
int	main()
{
	t_list	*par;
	t_list	*next_par;
	par = malloc(sizeof(t_list));
	next_par = malloc(sizeof(t_list));

	par->content = "hello world";
	next_par->content = "coucou";

	ft_lstiter(par, &ft_putstr;
}*/