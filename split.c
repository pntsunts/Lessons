/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:30:10 by pntsunts          #+#    #+#             */
/*   Updated: 2019/09/19 16:28:17 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		count(char *str)
{
	unsigned int i = 0;
	int len = 0;

	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] != '\0')
			len++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (len);
}

char	**ft_strsplit(char *str)
{
	int i = 0;
	int x = 0;
	int y = 0;
	char **res;

	if (!(res = (char **)malloc(sizeof(char *) * (count(str) + 1))))
		return (NULL);

	while (str[i])
	{
		y = 0;
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i++;
		if (!(res[x] = (char *)malloc(sizeof(char) * (count(str) + 1))))
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			res[x][y] = str[i];
			i++;
			y++;
		}
		res[x][y] = '\0';
		x++;
	}
	res[x] = NULL;
	return (res);
}

int main(int ac, char **av)
{
	int i = 0;
	char **res;
	if (ac == 2)
	{
		i = 1;
		res = ft_strsplit(av[1]);
		while (res[i])
		{
			printf("%s", res[i]);
			printf("%s", " ");
			i++;
		}
		i = i - 1;

		//printf("%s", res[i]);
		printf("\n");

	}
	return (0);
}


