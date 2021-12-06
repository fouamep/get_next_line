/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:51:37 by fbouanan          #+#    #+#             */
/*   Updated: 2021/12/01 20:51:41 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	int	ft_nchr(char *save)
{
	int	i;

	i = 0;
	while (save[i] && save[i] != '\n')
	{
		i++;
		if (save[i] == '\n')
			break ;
	}
	if (!save[i])
		return (-1);
	return (i);
}

static	char	*my_free(char **target, char **target2)
{
	free(*target);
	*target = NULL;
	if (target2 && *target2)
	{
		free(*target2);
		*target2 = NULL;
	}
	return (NULL);
}

static	void	ft_work(char **save, char **line, char **buf)
{
	int		newl;
	char	*tmp;

	my_free(buf, NULL);
	newl = ft_nchr(*save);
	if (newl < 0)
	{
		*line = ft_strdup(*save);
		my_free(save, NULL);
	}
	else
	{
		tmp = *save;
		*line = ft_substr(*save, 0, newl + 1);
		*save = ft_substr(*save, newl + 1, ft_strlen(*save));
		free (tmp);
		tmp = NULL;
	}
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*buf;
	char		*line;
	static char	*save[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	ret = 1;
	while (ret > 0 && ft_nchr(save[fd]) < 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (my_free(&save[fd], &buf));
		buf[ret] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
	}
	ft_work(&save[fd], &line, &buf);
	if (ft_strlen(line) == 0)
		return (my_free(&line, &buf));
	return (line);
}
