/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:52:50 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/05 17:21:34 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*origin;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!ptr)
		return (NULL);
	origin = ptr;
	while (*s1)
		*ptr++ = *s1++;
	*ptr++ = ' ';
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (origin);
}
