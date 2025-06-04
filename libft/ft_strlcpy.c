/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahour <achahour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:30:10 by achahour          #+#    #+#             */
/*   Updated: 2025/01/12 16:21:27 by achahour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (dstsize < 1)
		return (len);
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/* int	main()
{
	char	src[5] = "hola";
	char	dst[5] = "paco";
	size_t	size = 0;
	size_t	ret;

	ret = ft_strlcpy(dst, src, size);
	printf("%zu\n", ret);
	printf("%s\n", src);
	printf("%s\n", dst);
	return (0);
} */
