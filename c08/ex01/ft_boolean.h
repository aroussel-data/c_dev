/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 12:12:40 by marvin            #+#    #+#             */
/*   Updated: 2020/04/06 15:05:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define EVEN(x) (x % 2 == 0)
#define EVEN_MSG "I have an even number of arguments\n"
#define ODD_MSG "I have an odd number of arguments\n"

void	ft_putstr(char *str);
typedef _Bool t_bool;
t_bool	ft_is_even(int nbr);
