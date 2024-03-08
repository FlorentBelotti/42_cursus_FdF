/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:27:35 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/01 20:06:55 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Notes :

> Il faut gérer le retour '0' du ft_atoi en utilisant strcmp. */

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '+' || str[i] == ' ')
		i++;
	while (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = 10 * result + str[i] - '0';
		i++;
	}
	result = result * sign;
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return ((int)result);
}
