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

static void	check_tetra_line(char *line, int ***matrice, int nb_tetra, int cur)
{
	int i;
	int carac;

	i = 0;
	carac = 0;
	while (line[i] && carac <= 4)
	{
		if (line[i] == '.')
			matrice[cur][i] = 46;
		else if (line[i] != '#')
		{
			matrice[cur][i] = nb_tetra + 65;
			carac++;
		}
		else
			exit_error();
		i++;
	}
	if (i != 4 || carac != 4)
		exit_error();
}
/*
void	check_tetra_line_four(char *line, int ***matrice, int nb_tetra int line)
{
	int x;
	int y;

	y = 0;
	x = 0;
	check_tetra_line(line, matrice, nb_tetra, line);
	while(matrice[x])
	{
		if ()
	
	}	
}*/


static void	check_tetra_line_five(char *line, int ***matrice, int nb_tetra, int cur)
{
	if (line[0])
		exit_error();
	(void)cur;
	(void)matrice;
	(void)nb_tetra;
}

t_tab_fct	init_tab_fct(void)
{
	t_tab_fct tab_ftn_check[4];

	tab_ftn_check[0] = check_tetra_line;
	tab_ftn_check[1] = check_tetra_line;
	tab_ftn_check[2] = check_tetra_line;
	tab_ftn_check[3] = check_tetra_line;
	tab_ftn_check[4] = check_tetra_line_five;
	return (tab_ftn_check);
}
