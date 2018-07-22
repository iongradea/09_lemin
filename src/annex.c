/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:36:22 by igradea           #+#    #+#             */
/*   Updated: 2017/09/07 04:48:51 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/lem-in.h"

int   ft_tube(char **tab, int *flag)
{
  *flag = TUBE;
  ft_free_tab(tab);
  return (SUCCESS);
}

int		ft_index_room(t_data *data, char *room)
{
	int		i;

	i = 0;
	while (data->room[i])
	{
		if (!ft_strcmp(data->room[i], room))
			return (i);
		i++;
	}
	return (NOT_FOUND);
}
