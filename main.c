/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:51:43 by umartin-          #+#    #+#             */
/*   Updated: 2024/11/28 21:07:19 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern int	ft_strlen(char *str);
extern char	*ft_strcpy(char *str);

int	main(void)
{
	char	*test;

	test = ft_strcpy("yahoo");
	printf("STRLEN\n");
	printf("%d\n\n", ft_strlen("hola hola hola"));
	printf("STRCPY\n");
	printf("%s\n\n", test);
	return (0);
}
