/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:25:27 by fbouanan          #+#    #+#             */
/*   Updated: 2021/11/30 22:36:18 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*string;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		string = malloc(sizeof(char));
	else if (len > ft_strlen(s))
		string = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		string = malloc(sizeof (char) * (len + 1));
	if (!string)
		return (NULL);
	while (s[i] && i < len && i + start < ft_strlen(s))
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_strdup(char *s)
{
	char	*n;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	n = (char *) malloc (i + 1);
	if (!n)
		return (0);
	n[i] = '\0';
	while (i >= 0)
	{
		n[i] = s[i];
		i--;
	}
	return (n);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		ss1;
	int		ss2;
	char	*m;

	if (!s1 || !s2)
		return (NULL);
	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	m = malloc(sizeof(char) * (ss1 + ss2 + 1));
	if (!m)
		return (0);
	i = 0;
	while (i <= ss1)
	{
		m[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ss2)
		m[ss1++] = s2[i++];
	m[ss1] = '\0';
	free(s1);
	return (m);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
