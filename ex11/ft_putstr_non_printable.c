/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:20:06 by stee              #+#    #+#             */
/*   Updated: 2025/08/12 16:56:57 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_conversion(int input)
{
	int	temp;
	int	i;
	char	*output;
	
	i = 1;
	temp = input % 16;
	if (temp < 10)
		temp += 48;
	else
		temp += 55;
	while (output[i])
	{
		output[i] = temp;
		i++;
	}
	return (output);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar('\');
			ft_putchar(str[i]);
		else
			ft_putchar(ft_conversion(str[i]));
		i++;
	}
	return (0);
}

int	main(void)
{

	char	str[] = "this is not \n printable ? 234";
	
	ft_putstr_non_printable(str);
	return 0;
}
