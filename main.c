/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:51:43 by umartin-          #+#    #+#             */
/*   Updated: 2024/12/02 15:50:28 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

extern size_t	ft_strlen(char *str);
extern char		*ft_strcpy(char *dest, const char *src);
extern int		ft_strcmp(const char *s1, const char *s2);

void	test_ft_strlen(void)
{
	printf("\n--------------ft_strlen---------------\n\n");

	char *str1 = "123456789";
	char *str2 = "asdfasdfasdfasdf";
	char *str3 = "";
	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
	// char *str5 = NULL;

	printf("strlen is \t [%ld] \nft_strlen is \t [%ld]\n\n", strlen(str1), ft_strlen(str1));
	printf("strlen is \t [%ld] \nft_strlen is \t [%ld]\n\n", strlen(str2), ft_strlen(str2));
	printf("strlen is \t [%ld] \nft_strlen is \t [%ld]\n\n", strlen(str3), ft_strlen(str3));
	printf("strlen is \t [%ld] \nft_strlen is \t [%ld]\n\n", strlen(str4), ft_strlen(str4));
	// printf("strlen is \t [%ld] \nft_strlen is \t [%ld]\n\n", strlen(str5), ft_strlen(str5));
}

void	test_ft_strcpy(void)
{
	printf("\n--------------ft_strcpy---------------\n\n");

	char	dst[300];

	char *str1 = "123456789";
	char *str2 = "asdfasdfasdfasdf";
	char *str3 = "";
	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
	char *str5 = "this is a very looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong string to test a function";
	// char *str6 = NULL;

	printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst, str1), ft_strcpy(dst, str1));
	printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst, str2), ft_strcpy(dst, str2));
	printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst, str3), ft_strcpy(dst, str3));
	printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst, str4), ft_strcpy(dst, str4));
	printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst, str5), ft_strcpy(dst, str5));
	// printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst, str6), ft_strcpy(dst, str6));
}

void	test_ft_strcmp(void)
{
	printf("\n--------------ft_strcmp---------------\n\n");

	char *str1 = "6666123456789";
	char *str2 = "6666asdfasdfasdfasdf";
	char *str3 = "";
	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
	char *str5 = NULL;

	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str1, str2), ft_strcmp(str1, str2));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str2, str3), ft_strcmp(str2, str3));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str3, str4), ft_strcmp(str3, str4));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str4, str3), ft_strcmp(str4, str3));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str3, str2), ft_strcmp(str3, str2));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str2, str1), ft_strcmp(str2, str1));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str1, str1), ft_strcmp(str1, str1));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str2, str2), ft_strcmp(str2, str2));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str3, str3), ft_strcmp(str3, str3));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str4, str4), ft_strcmp(str4, str4));
	// printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str5, str4), ft_strcmp(str5, str4));
}

int	main(void)
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	return (0);
}
