/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 03:00:10 by juannune          #+#    #+#             */
/*   Updated: 2025/11/27 04:59:55 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*node;
	void	*newcontent;

	lstnew = NULL;
	while (lst)
	{
		newcontent = f(lst->content);
		if (!newcontent)
		{
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		node = ft_lstnew(newcontent);
		if (!node)
		{
			del(newcontent);
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, node);
		lst = lst->next;
	}
	return (lstnew);
}
