/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:46:26 by igradea           #+#    #+#             */
/*   Updated: 2017/09/07 04:51:59 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

static t_buffer	*create_new_buf(int fd)
{
	t_buffer	*buf;

	if (!(buf = (t_buffer*)ft_memalloc(sizeof(*buf))))
		return (NULL);
	buf->fd = fd;
	buf->offset = NULL;
	buf->next = NULL;
	buf->previous = NULL;
	return (buf);
}

static int		get_or_create_buf(int fd, t_buffer **buf)
{
	t_buffer	*tmp;

	if (!(*buf))
	{
		if (!(*buf = create_new_buf(fd)))
			return (ERRGN);
		return (SUCCESS);
	}
	while ((*buf)->previous && (*buf)->fd != fd)
		*buf = (*buf)->previous;
	while ((*buf)->next && (*buf)->fd != fd)
		*buf = (*buf)->next;
	if ((*buf)->fd != fd)
	{
		if (!(tmp = create_new_buf(fd)))
			return (ERRGN);
		(*buf)->next = tmp;
		tmp->previous = *buf;
		*buf = tmp;
	}
	return (SUCCESS);
}

static int		reader(t_buffer *buf)
{
	int			octet_read;

	octet_read = read(buf->fd, buf->buffer, BUFF_SIZE);
	if (octet_read == -1)
		return (ERRGN);
	if (octet_read == 0)
		return (END_OF_FILE);
	(buf->buffer)[octet_read] = '\0';
	buf->offset = buf->buffer;
	return (SUCCESS);
}

static char		*add_to_line(char *line, char *buf_offset)
{
	char		*updated_line;
	int			line_len;
	int			offset_size;

	line_len = 0;
	offset_size = 0;
	if (line)
		line_len = (int)ft_strlen(line);
	while (buf_offset[offset_size] && buf_offset[offset_size] != '\n')
		offset_size++;
	if (!(updated_line = (char*)ft_memalloc(line_len + offset_size + 1)))
		return (NULL);
	if (line)
	{
		ft_strcpy(updated_line, line);
		free(line);
	}
	ft_strncpy(updated_line + line_len, buf_offset, offset_size);
	updated_line[line_len + offset_size] = '\0';
	return (updated_line);
}

int				get_next_line(const int fd, char **line)
{
	static t_buffer	*buf = NULL;
	int				ret;

	if (fd < 0 || line == NULL || !(get_or_create_buf(fd, &buf)))
		return (ERRGN);
	*line = NULL;
	while (buf->offset || (ret = reader(buf)) == SUCCESS)
	{
		*line = add_to_line(*line, buf->offset);
		buf->offset = ft_strchr(buf->offset, '\n');
		if (buf->offset)
		{
			buf->offset = *(buf->offset + 1) == '\0' ? NULL : buf->offset + 1;
			return (LINE_READ);
		}
	}
	if (ret == ERRGN)
		return (ERRGN);
	if (*line == NULL)
		return (END_OF_FILE);
	return (LINE_READ);
}
