/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:56:33 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:01:53 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "ft_printf.h"

/*
// fractal names
*/
# define M "Mandelbrot" 


/*
// default parameters 
*/
# define 


/*
// window and image parameters
*/
typedef struct s_win
{
	void	*mlx;

}			t_win;



/*
// main.c
*/
void	make_image(t_fr *fr);



#endif