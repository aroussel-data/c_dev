/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 10:05:12 by marvin            #+#    #+#             */
/*   Updated: 2020/03/16 18:16:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int t;
	int temp;
	
	i = 0;
	temp = 0;
	while (i < (size-1)){
		t=0;
		while (t < (size-1))
		{
			if (tab[t] > tab[t+1])
			{
				temp = tab[t];
				tab[t] = tab[t+1];
				tab[t+1] = temp;
			}
			t++;
		}
		i++;
	}
}
