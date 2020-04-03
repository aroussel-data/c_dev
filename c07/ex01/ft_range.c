/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 09:53:08 by marvin            #+#    #+#             */
/*   Updated: 2020/04/03 11:08:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *my_array;
	int i = 0;
	
	if (min >= max)
		return NULL;

	my_array = malloc((max - 1) * 4);
	while (min < max)
	{
		my_array[i] = min;
		min++;
		i++;
	}
	return my_array;
}

int	main(void)
{
	// can only use malloc, so create an empty int array with malloc of right size
	// how do we computer the size needed between two ints?
	int *test_array = ft_range(0, 9);
	printf("%d\n", test_array[0]);
	printf("%d\n", test_array[1]);
	printf("%d\n", test_array[2]);
	printf("%d\n", test_array[3]);
	printf("%d\n", test_array[4]);
	printf("%d\n", test_array[5]);
	printf("%d\n", test_array[6]);
	printf("%d\n", test_array[7]);
	printf("%d\n", test_array[8]);
	printf("%d\n", test_array[9]);
}
