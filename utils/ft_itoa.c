/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:33:55 by tturner           #+#    #+#             */
/*   Updated: 2022/05/04 12:33:55 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/utils.h"

static void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = (unsigned char *)malloc(count * size);
	if (mem == NULL)
		return (NULL);
	while (i < count * size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

int	ft_countnbr(int nb)
{
	int	count;

	count = 1;
	if (nb < 0)
		count++;
	while (nb > 9 || nb < -9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*rtn;
	int				len;
	unsigned int	num;

	len = ft_countnbr(n);
	rtn = (char *)ft_calloc(len + 1, sizeof(char));
	if (rtn == NULL)
		return (NULL);
	if (n < 0)
	{
		rtn[0] = '-';
		num = -n;
	}
	else
		num = n;
	rtn[len] = '\0';
	while (len > 0 && rtn[len - 1] != '-')
	{
		rtn[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (rtn);
}
