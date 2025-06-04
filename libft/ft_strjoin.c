/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahour <achahour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:05:18 by achahour          #+#    #+#             */
/*   Updated: 2025/01/21 16:12:36 by achahour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strjoin_first(char	*str, const char	*s1)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (!str)
		return (NULL);
	j = ft_strjoin_first(str, s1);
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}

/* int main() {
	char *str1 = ft_strjoin("HOLA", NULL);
	printf("str1: %s\n", str1 ? str1 : "(null)");

	char *str2 = ft_strjoin(NULL," MUNDO");
    printf("str2: %s\n", str2 ? str2 : "(null)");

	char *str3 = ft_strjoin("HOLA", " MUNDO");
    printf("str3: %s\n", str3 ? str3 : "(null)");
}
 */