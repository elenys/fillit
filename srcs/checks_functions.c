/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:39:58 by bmartins          #+#    #+#             */
/*   Updated: 2015/12/08 18:21:07 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

static void	check_tetra_line(char *line, t_tetra matrice, int nb_tetra, int cur)
{
	int i;

	i = 0;
	ft_putstr("check_tetra_line line=");
	ft_putendl(line);
	while (line[i])
	{
		if (line[i] == '.')
			matrice[cur][i] = 46;
		else if (line[i] == '#')
			matrice[cur][i] = nb_tetra + 65;
		else
			exit_error();
		i++;
	}
	if (i != 4)
		exit_error();
}

void	check_tetra_line_four(char *line, t_tetra matrice, int nb_tetra, int cur)
{
	int	x;
	int	y;
	int	last_x;
	int	last_y;
	int	piece;

	y = 0;
	x = 0;
	piece = 0;
	last_x = -1;
	last_y = -1;
	check_tetra_line(line, matrice, nb_tetra, cur);
	while(x < 4)
	{
		if (matrice[x][y] != 46)
		{
			piece++;
			#include <stdio.h>
			printf("line = %d \nlast_x= %d last_y = %d x = %d y = %d\n",matrice[x][y],  last_x , last_y, x, y);
			if (last_x == -1 && last_y == -1)
			{
		 		last_x = x;
				last_y = y;
			}
			else if(x - last_x == 1 && y - last_y == 0)
			{
		 		last_x = x;
				last_y = y;
			}
			else if (x - last_x == 0 && y - last_y == 1)
			{
		 		last_x = x;
				last_y = y;
			}
			else
				exit_error();
			ft_putendl("bloc++");
		}
		y++;
		if (y == 4)
		{
			y = 0;
			x++;
		}
	}
	if (piece != 4)
		exit_error();
}


static void	check_tetra_line_five(char *line, t_tetra matrice, int nb_tetra, int cur)
{
	if (line[0])
		exit_error();
	(void)cur;
	(void)matrice;
	(void)nb_tetra;
}

t_tab_fct	*init_tab_fct(void)
{
	static t_tab_fct tab_fct_check[6];

	tab_fct_check[0] = &check_tetra_line;
	tab_fct_check[1] = &check_tetra_line;
	tab_fct_check[2] = &check_tetra_line;
	tab_fct_check[3] = &check_tetra_line_four;
	tab_fct_check[4] = &check_tetra_line_five;
	tab_fct_check[5] = 0;
	return (tab_fct_check);
}
