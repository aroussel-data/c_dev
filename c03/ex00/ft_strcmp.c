/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 21:28:17 by marvin            #+#    #+#             */
/*   Updated: 2020/03/18 14:03:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int i;
	int s1_result;
	int s2_result;

	i = 0;
	s1_result = 0;
	s2_result = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		s1_result = s1_result + s1[i];
		s2_result = s2_result + s2[i];
		i++;
	}

	if (s1_result == s2_result)
	{
		return 0;
	}
	else if (s1_result < s2_result)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
