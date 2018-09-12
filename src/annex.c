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

int   ft_tube(char **tab, t_flag *flag)
{
  DEBUG ? ft_printf("launching ft_tube ...\n") : DEBUG;
  flag->process = TUBE;
  ft_free_tab(tab);
  return (SUCCESS);
}

int		ft_index_room(t_data *data, char *room)
{
	int		i;

  DEBUG ? ft_printf("launching ft_index_room ...\n") : DEBUG;
	i = 0;
	while (data->room[i])
	{
		if (!ft_strcmp(data->room[i], room))
			return (i);
		i++;
	}
	return (NOT_FOUND);
}

void   ft_ch_st_end_count(t_data *data)
{
  DEBUG ? ft_printf("launching ft_ch_st_end_count ...\n") : DEBUG;
  if (data->st_cmd != 1)
    exit(PRT_ERROR);
  if (data->end_cmd != 1)
    exit(PRT_ERROR);
}
