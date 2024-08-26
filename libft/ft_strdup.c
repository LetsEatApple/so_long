/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:04:12 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/02 20:49:37 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(s) +1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* int main()
{
    char source[] = "GeeksForGeeks";
 
    char* target = ft_strdup(source); 
    printf("%s\n", target);
	
	char s[] = "GeeksForGeeks";
    char* t = strdup(s); 
    printf("%s\n", t);
	free(t);
    return 0;
} */