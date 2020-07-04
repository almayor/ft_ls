/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:17:41 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 03:29:17 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define OPTIONS	"ACFGLRSTUacdfhilmnopqrstuvx1"

typedef struct	s_options
{
	int			A;
	int			C;
	int			F;
	int			G;
	int			L;
	int			R;
	int			S;
	int			T;
	int			U;
	int			a;
	int			c;
	int			d;
	int			f;
	int			h;
	int			i;
	int			k;
	int			l;
	int			m;
	int			n;
	int			o;
	int			p;
	int			q;
	int			r;
	int			s;
	int			t;
	int			u;
	int			v;
	int			x;
	int			_1;
}				t_options;

extern t_options	g_opt;

int				get_options(char ***argv);
void			set_option_1();
void			set_option_A();
void			set_option_C();
void			set_option_F();
void			set_option_G();
void			set_option_L();
void			set_option_R();
void			set_option_S();
void			set_option_T();
void			set_option_U();
void			set_option_a();
void			set_option_c();
void			set_option_d();
void			set_option_f();
void			set_option_h();
void			set_option_i();
void			set_option_k();
void			set_option_l();
void			set_option_m();
void			set_option_n();
void			set_option_o();
void			set_option_p();
void			set_option_q();
void			set_option_r();
void			set_option_s();
void			set_option_t();
void			set_option_u();
void			set_option_v();
void			set_option_x();
void			set_options_env();

#endif
