/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 11:47:22 by marvin            #+#    #+#             */
/*   Updated: 2020/04/03 15:26:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *my_array;
	int i;

	if (min >= max)
	{
		*range = NULL;
		return 0;
	}

	my_array = malloc((max - min) * 4);
	if (my_array == NULL)  //if malloc did not succeed
		return -1;
	i = 0;
	while (min < max)
	{
		my_array[i] = min;
		min++;
		i++;
	}
	*range = my_array;
	return i;
}

int	main(void)
{
	int *test_array = NULL;

	printf("%d\n", ft_ultimate_range(&test_array, -5, 5));
	printf("%d\n", test_array[0]);
}
