/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juannune <juannune@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 03:00:10 by juannune          #+#    #+#             */
/*   Updated: 2025/11/25 04:47:27 by juannune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*nodenew;

	lstnew = NULL;
	while (lst)
	{
		nodenew = ft_lstnew(f(lst->content));
		if (!nodenew)
		{
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, nodenew);
		lst = lst->next;
	}
	return (lstnew);
}

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *lstnew;
    t_list  *nodenew;
    void    *new_content;

    lstnew = NULL;
    while (lst)
    {
        new_content = f(lst->content);
        if (!new_content)
        {
            ft_lstclear(&lstnew, del);
            return (NULL);
        }
        nodenew = ft_lstnew(new_content);
        if (!nodenew)
        {
            del(new_content);
            ft_lstclear(&lstnew, del);
            return (NULL);
        }
        ft_lstadd_back(&lstnew, nodenew);
        lst = lst->next;
    }
    return (lstnew);
}
