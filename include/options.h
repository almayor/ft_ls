/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:17:41 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 14:30:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define OPTIONS	"@AFGPRSUacdeflmprt1"

typedef struct	s_options
{
	int			at;
	int			A;
	int			F;
	int			G;
	int			P;
	int			R;
	int			S;
	int			T;
	int			U;
	int			a;
	int			c;
	int			d;
	int			e;
	int			f;
	int			h;
	int			i;
	int			l;
	int			m;
	int			n;
	int			o;
	int			p;
	int			r;
	int			s;
	int			t;
	int			u;
	int			_1;
}				t_options;

t_options		g_opt;

int				get_options(char ***argv);
void			set_option_at();
void			set_option_1();
void			set_option_A();
void			set_option_F();
void			set_option_G();
void			set_option_P();
void			set_option_R();
void			set_option_S();
void			set_option_T();
void			set_option_U();
void			set_option_a();
void			set_option_c();
void			set_option_d();
void			set_option_e();
void			set_option_f();
void			set_option_h();
void			set_option_i();
void			set_option_l();
void			set_option_m();
void			set_option_n();
void			set_option_o();
void			set_option_p();
void			set_option_r();
void			set_option_s();
void			set_option_t();
void			set_option_u();
void			set_options_env();

#endif
