/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <jd-halle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:18:34 by jd-halle          #+#    #+#             */
/*   Updated: 2024/10/01 01:11:53 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_and_store(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = trim_stash(stash);
	return (line);
}

char	*read_and_store(int fd, char *stash)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		stash = update_stash(stash, buff);
		if (!stash)
			break ;
		if (ft_strchr(stash, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (bytes_read == -1 || (bytes_read == 0 && *stash == '\0'))
	{
		free (stash);
		return (NULL);
	}
	return (stash);
}

char	*update_stash(char	*stash, char *buff)
{
	char	*temp;
	int		i;

	temp = malloc((ft_strlen(stash) + ft_strlen(buff) + 1) * sizeof(char));
	if (!temp)
	{
		free (stash);
		return (NULL);
	}
	i = 0;
	while (stash[i])
	{
		temp[i] = stash[i];
		i++;
	}
	temp[i] = 0;
	ft_strcat(temp, buff);
	free (stash);
	return (temp);
}

char	*extract_line(char *stash)
{
	char	*line;
	char	*newline_pos;
	int		line_len;

	newline_pos = ft_strchr(stash, '\n');
	if (newline_pos)
	{
		line_len = newline_pos - stash + 1;
		line = ft_strndup(stash, line_len);
	}
	else
		line = ft_strdup(stash);
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	return (line);
}

char	*trim_stash(char *stash)
{
	char	*newstash;
	char	*newline_pos;

	newline_pos = ft_strchr(stash, '\n');
	if (newline_pos)
		newstash = ft_strdup(newline_pos +1);
	else
		newstash = NULL;
	free(stash);
	return (newstash);
}
