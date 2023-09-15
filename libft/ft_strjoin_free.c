/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:49:28 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/15 15:13:35 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	ft_strlcat(p, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1)
		free(s1);
	return (p);
}
