/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:17:41 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 03:41:25 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define OPTIONS	"ACFGLRSTUacdfhilmnopqrstuvx1"

typedef struct	s_options
{
	int			aa;
	int			cc;
	int			ff;
	int			gg;
	int			ll;
	int			rr;
	int			ss;
	int			tt;
	int			uu;
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
void			set_option_aa();
void			set_option_cc();
void			set_option_ff();
void			set_option_gg();
void			set_option_ll();
void			set_option_rr();
void			set_option_ss();
void			set_option_tt();
void			set_option_uu();
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
