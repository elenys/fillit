/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:33:14 by bmartins          #+#    #+#             */
/*   Updated: 2015/12/08 18:20:08 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

# include "libft.h"
# include "get_next_line.h"

# include <fcntl.h>

typedef int t_tetra[3][3];
typedef void (*t_tab_fct)(char *line, int ***matrice, int nb_tetra, int cur);

void		exit_error(void);

#endif
