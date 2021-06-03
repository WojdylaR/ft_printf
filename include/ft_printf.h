/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/07/01 17:49:16 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct		s_arg
{
	char			type;
	int				flag;
	int				blanck;
	int				prec;
	char			*res;
	struct s_arg	*next;
}					t_arg;

char				*ft_test_s(t_arg *list, va_list list_arg, const char *str);
int					condition_7(t_arg *list, int x, const char *str);
int					condition_3(t_arg *list, const char *str);
int					condition_4(t_arg *list, int x);
int					check_point(const char *str);
void				new_res(t_arg *list);
char				*ft_fill_char(unsigned int c);
int					condition_p(t_arg *list, const char *str);
int					czero(t_arg *list);
int					check_point(const char *str);
void				ft_fill_arg(t_arg *list, const char *str, va_list list_arg);
int					ft_printf(const char *str, ...);
int					new_list(t_arg *list, const char *str, va_list list_arg);
char				*ft_fill_char(unsigned int c);
char				*ft_itoa_base(unsigned long long value, char *base);
char				*ft_put_address(unsigned long long p);
char				*ft_utoa(unsigned int n);
int					ft_putflag(t_arg *list, const char *str);
void				ft_free_list(t_arg *list);
void				new_res(t_arg *list);

#endif
