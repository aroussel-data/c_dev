/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 15:10:49 by marvin            #+#    #+#             */
/*   Updated: 2020/03/17 15:48:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	ft_str_is_alpha(char *str)
{
	int i;
	int num_alpha;
	int num_non_alpha;

	i = 0;
	num_alpha = 0;
	num_non_alpha = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
		{
			num_alpha++;
		}
		else
		{
			num_non_alpha++;
		}
		i++;
	}
	if (num_non_alpha)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
