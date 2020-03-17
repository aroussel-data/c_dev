/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:23:59 by marvin            #+#    #+#             */
/*   Updated: 2020/03/17 20:55:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strupcase(char *str)
{
	if (*str >= 97 && *str <= 122)
	{
		*str = *str-32;
	}
}

void	ft_strlowcase(char *str)
{
	if (*str >= 65 && *str <= 90)
	{
		*str = *str+32;
	}
}

int 	ft_str_is_alpha(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int 	ft_str_is_num(char c)
{
	if ((c >= 48 && c <= 57))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int word_start;

	i = 0;
	word_start = 1;
	while (str[i] != '\0')
	{
		if (ft_str_is_alpha(str[i]) && word_start)
		{
			ft_strupcase(&str[i]);
			word_start = 0;
		}
		else if (ft_str_is_alpha(str[i]))
		{
			ft_strlowcase(&str[i]);
			word_start = 0;
		}
		else if (!(ft_str_is_alpha(str[i])) && word_start)
		{
			word_start = 0;
		}
		if (!(ft_str_is_num(str[i])) && !(ft_str_is_alpha(str[i])))
		{
			word_start = 1;
		}
		i++;
	}
	return str;
}
