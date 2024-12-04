/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:51:43 by umartin-          #+#    #+#             */
/*   Updated: 2024/12/04 18:01:11 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern int errno;

extern size_t	ft_strlen(char *str);
extern char		*ft_strcpy(char *dest, const char *src);
extern int		ft_strcmp(const char *s1, const char *s2);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern char		*ft_strdup(const char *s);

void	test_ft_strdup(void)
{
	printf("\n--------------ft_strdup---------------\n\n");

	char *str1 = "123456789";
	char *str2 = "asdfasdfasdfasdf";
	char *str3 = "";
	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
	char *str5 = "this is a very looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong string to test a function";

	char *dup1 = strdup(str1);
	char *dup1f = ft_strdup(str1);
	printf("strdup is \t [%s] \n",	dup1);
	printf("ft_strdup is \t [%s] \n\n", dup1f);
	free(dup1);
	free(dup1f);

	dup1 = strdup(str2);
	dup1f = ft_strdup(str2);
	printf("strdup is \t [%s] \nft_strdup is \t [%s]\n\n", dup1, dup1f);
	free(dup1);
	free(dup1f);
	dup1 = strdup(str2);
	dup1f = ft_strdup(str2);
	printf("strdup is \t [%s] \nft_strdup is \t [%s]\n\n", dup1, dup1f);
	free(dup1);
	free(dup1f);
	dup1 = strdup(str3);
	dup1f = ft_strdup(str3);
	printf("strdup is \t [%s] \nft_strdup is \t [%s]\n\n", dup1, dup1f);
	free(dup1);
	free(dup1f);
	dup1 = strdup(str4);
	dup1f = ft_strdup(str4);
	printf("strdup is \t [%s] \nft_strdup is \t [%s]\n\n", dup1, dup1f);
	if (dup1)
		free(dup1);
	if (dup1f)
		free(dup1f);
	dup1 = strdup(str5);
	dup1f = ft_strdup(str5);
	printf("strdup is \t [%s] \nft_strdup is \t [%s]\n\n", dup1, dup1f);
	free(dup1);
	free(dup1f);
}

void	test_ft_read(void)
{
	printf("\n--------------ft_read---------------\n\n");

	char *file1 = "read.txt";
	char *file2 = "";
	char *buf1 = malloc(sizeof(char) * 50);
	char *buf2 = malloc(sizeof(char) * 50);
	
	printf("--------------ft_read from file---------------\n\n");
	int fd1 = open(file1, O_RDONLY);
	if (fd1 == -1)
	{
		printf("Error opening file 1\n");
		return ;
	}
	errno = 0;
	ssize_t bytes_read = read(fd1, buf1, 40);
	printf("read() return value \t [%zd]\n", bytes_read);
	buf1[bytes_read] = '\0';
	printf("read() read buf \t [%s]\n", buf1);
	printf("read() errno \t\t [%d] \t [%s]\n\n", errno, strerror(errno));
	errno = 0;
	close(fd1);
	fd1 = open(file1, O_RDONLY);
	if (fd1 == -1)
	{
		printf("Error opening file 1\n");
		return ;
	}
	ssize_t bytes_read2 = ft_read(fd1, buf1, 40);
	printf("ft_read() return value \t [%zd]\n", bytes_read2);
	buf1[bytes_read2] = '\0';
	printf("ft_read() read buf \t [%s]\n", buf1);
	printf("ft_read() errno \t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	
	printf("--------------ft_read from empty file---------------\n\n");
	int	fd2 = open(file2, O_RDONLY);
	bytes_read = read(fd2, buf2, 40);
	printf("read() return value \t [%zd]\n", read(fd2, buf2, 40));
	if (bytes_read != -1)
		buf2[bytes_read] = '\0';
	else
		buf2[0] = '\0';
	printf("read() read buf \t [%s]\n", buf2);
	printf("read() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	errno = 0;
	bytes_read2 = ft_read(fd2, buf2, 40);
	printf("ft_read() return value \t [%zd]\n", ft_read(fd2, buf2, 40));
	if (bytes_read2 != -1)
		buf2[bytes_read2] = '\0';
	else
		buf2[0] = '\0';
	printf("ft_read() read buf \t [%s]\n", buf2);
	printf("ft_read() errno \t [%d] \t [%s]\n", errno, strerror(errno));
	close(fd2);
	printf("\n");

	printf("--------------ft_read from stdin---------------\n\n");
	errno = 0;
	// printf("read() return value \t [%zd]\n", read(fd1, 0, 40));
	printf("read() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	errno = 0;
	printf("ft_read() return value \t [%zd]\n", ft_read(fd1, 0, 40));
	printf("ft_read() errno \t [%d] \t [%s]\n", errno, strerror(errno));
	close(fd1);
	printf("\n");

	printf("--------------ft_read from stdin---------------\n\n");
	errno = 0;
	printf("read() return value \t [%zd]\n", read(0, buf1, 40));
	printf("read() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	errno = 0;
	printf("ft_read() return value \t [%zd]\n", ft_read(0, buf1, 40));
	printf("ft_read() errno \t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");

	if (buf1)
		free(buf1);
	if (buf2)
		free(buf2);
}

void	test_ft_write(void)
{
	printf("\n--------------ft_write---------------\n\n");
	char *buf = "TEST SENTENCE TO TEST WRITE.\n";
	int fd = 1;
	int n = strlen(buf);
	errno = 0;
	printf("write() return value \t\t [%zd]\n", write(fd, buf, n));
	printf("ft_write() return value \t [%zd]\n", ft_write(fd, buf, n));
	printf("\n");
	errno = 0;
	printf("write() return value \t\t [%zd]\n", write(fd, 0, n));
	printf("write() errno \t\t\t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");
	errno = 0;
	printf("ft_write() return value \t [%zd]\n", ft_write(fd, 0, n));
	printf("ft_write() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");
	errno = 0;
	printf("write() return value \t\t [%zd]\n", write(-1, 0, n));
	printf("write() errno \t\t\t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");
	errno = 0;
	printf("ft_write() return value \t [%zd]\n", ft_write(-1, 0, n));
	printf("ft_write() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");
}

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
	test_ft_write();
	test_ft_strdup();
	// test_ft_read();
	return (0);
}
