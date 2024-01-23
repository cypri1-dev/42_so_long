/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:57:32 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/18 12:28:06 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_so_long.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (s[size])
	{
		size++;
	}
	dest = malloc((sizeof(char) * (size + 1)));
	if (!dest)
	{
		return (NULL);
	}
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
