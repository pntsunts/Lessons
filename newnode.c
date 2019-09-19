/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:18:10 by pntsunts          #+#    #+#             */
/*   Updated: 2019/09/11 09:37:48 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t	ft_strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int i = 0;
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


t_list	*newnode(char *name, int age)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));

	node->name = ft_strdup(name);
	node->age = age;
	node->next = NULL;
	return (node);
}

void	print_list(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		printf("%s %d", lst->name, lst->age);
		lst = lst->next;
	}
	printf("\n");
}

int main()
{
	t_list *head;

	head = newnode("Peter", 26);
	print_list(head);
	return (0);
}
