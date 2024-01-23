/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:00:46 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/16 16:26:54 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_so_long.h"

char	*ft_strrchr(const char *str, int searchedChar)
{
	int	len;

	len = ft_strlen((char *)str);
	while (str[len] != (unsigned char)searchedChar)
	{
		if (len == 0 && str[len] != searchedChar)
			return ((char *)0);
		len--;
	}
	return ((char *)&str[len]);
}
