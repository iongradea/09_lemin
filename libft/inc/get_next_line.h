/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:36:43 by igradea           #+#    #+#             */
/*   Updated: 2017/09/07 10:59:14 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4

# define SUCCESS 2
# define LINE_READ 1
# define END_OF_FILE 0
# define ERRGN (-1)

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		s_buffer
{
	int				fd;
	char			buffer[BUFF_SIZE + 1];
	char			*offset;
	struct s_buffer	*next;
	struct s_buffer	*previous;
}					t_buffer;

int					get_next_line(const int fd, char **line);

#endif
