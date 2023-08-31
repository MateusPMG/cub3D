/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:01:00 by mpatrao           #+#    #+#             */
/*   Updated: 2023/05/25 14:01:13 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;

	if (nelem == 0 || elsize == 0)
	{
		nelem = 1;
		elsize = nelem;
	}
	p = (void *)malloc(nelem * elsize);
	if (p)
		ft_bzero(p, nelem * elsize);
	return (p);
}
