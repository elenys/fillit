/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:19:42 by bmartins          #+#    #+#             */
/*   Updated: 2015/12/08 19:00:34 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			exit_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

static int		parse_file(int fd, int nb_tetra, t_tetra tab_tetra[])
{
	char		*line;
	int			nb_line;
	int			return_value;
	t_tab_fct	*tab_fun_check;

	line = 0;
	nb_line = 0;
	return_value = 2;
	tab_fun_check = init_tab_fct();
	ft_putendl("Strarting parse piece");
	while ((return_value = get_next_line(fd, &line)) > 0 && nb_tetra <= 26)
	{
		if (nb_line == 5)
		{
			ft_putendl("1 piece parsed");
			nb_line = 0;
			nb_tetra++;
		}
		tab_fun_check[nb_line](line, tab_tetra[nb_tetra], nb_tetra, nb_line);
		nb_line++;
	}
	if (nb_line == 5 && return_value == 0) //a verifier pour les conditions
		nb_tetra++;
	else if (return_value < 0 || nb_tetra == 0) //verifier qu'il n'y a plus rien dans le buffer genre rv value > 0 et nb_tet = 26 
		exit_error();
	return (nb_tetra);
}

static int parser(char *file_name, t_tetra tab_tetra[])
{
	int			fd;
	int			nb_tetra;

	nb_tetra = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_error();
	nb_tetra = parse_file(fd, nb_tetra, tab_tetra);
	return (nb_tetra);
}

int				main(int ac, char **av)
{
	int			nb_tetra;
	t_tetra		tab_tetra[28];

	if (ac == 2)
	{
		ft_putendl("parsing");
		nb_tetra = parser(av[1], tab_tetra);
	}
	else
		exit_error();
	return (0);
}
