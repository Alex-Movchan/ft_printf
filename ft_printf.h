#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <wchar.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdarg.h>

#define A(x) (x < 0 ? -(x) : x)

typedef struct      s_srt
{
    char            letar;
    char            zero_or_minus;
    char            plus;
    char            space;
    int             hesh;
    int             size;
    int             accur;
    int             width;
    int             rs;
    int             fd;
    int             ap;
    int             dolar;
    char            chr;
}                   t_srt;

int                 ft_printf(__const char *format, ...);
int			        ft_format(const char *format, va_list ap);
t_srt   	        *inicial_struct(t_srt *lst);
t_srt	            *ft_print_format(t_srt *lst, const char *str, int *i, va_list ap);
int		            atoidig(const char *str, int *i);
void	            ft_specifiers(const char *str, int *i, t_srt *list);
int		            flag_format(char c, t_srt *lst);
int		            add_dot(const char *str, int *i, t_srt *lst, va_list ap);
void	            ft_color(const char *s, int *i, va_list ap, t_srt *lst);
void                ft_color_print(char *str);
int		            tayp(char c);
intmax_t	        signed_size(va_list ap, t_srt *lst);
uintmax_t	        unsigned_size(va_list ap, t_srt *lst);
char	            *ft_getdouble(va_list ap, t_srt *lst);
char	            *getstr(va_list ap, t_srt *lst);
char	            *ft_cast_f(va_list ap, t_srt *lst);
char	            *ft_cast_e(va_list ap,t_srt *lst);
char	            *ft_cast_el(va_list ap, t_srt *lst);
char	            *ft_cast_gi(va_list ap, t_srt *lst);
char	            *ft_cast_a(va_list ap,t_srt *lst);
char	            *ft_str_dable_a(long double nb, int len, t_srt *lst);
char	            *ft_str_zero(long double nb, t_srt *lst, char *s);
void	            ft_ppp(char *c, char *b);
char	            *ft_okrug_a(char *str);
char	            *ft_zero(int len);
char	            ft_char(int a);
long double         rang(long double nb, int *i);
char                *ft_strs(char   *s, int *i, int nb);
char	            *ft_pow_a(int pow);
char	            *ft_getstr_a(long double nb, t_srt *lst);
char                *ft_str_double(long double nb, t_srt *lst);
char               	*ft_okrug(long double nb, t_srt *lst);
char                *ft_cast(char *s1, char *s2);
char		        *ft_pow(long double	nb, int len);
char	            *ft_cast_al(va_list ap, t_srt *lst);
char	            *ft_get_str_e(long double nb, t_srt *lst);
char	            *ft_plus(char *str, t_srt *lst);
char	            *ft_width(char *str, t_srt *lst);
char	            *ft_accur(char *str, t_srt *lst);
char	            *get_str(va_list ap, t_srt *lst);
int                 ft_print(t_srt *lst, va_list ap, va_list tmp);
long double         ft_r_nbr(long double nbr);
char	            *ft_strcpy_rev(char *s1, char *s2, char c, int j);
char	            *ft_itoa_base(uintmax_t nb, int base);
char                *ft_accur_digits(char *str, t_srt *lst);
char                *ft_strhesh(char *str, t_srt *lst);
char	            *ft_cast_unsigned(va_list ap, t_srt *lst, int base);
char	            *ft_cast_long(va_list ap, t_srt *lst, int base);
char	            *ft_cast_dl(va_list ap, t_srt *lst);
char	            *ft_cast_di(va_list ap, t_srt *lst);
char                *ft_space(char *str, char c, int len, t_srt *slt);
char	            *ft_cast_xl(va_list ap, t_srt *lst);
char 				*itoa(long long int n);
char                *ft_strcast_p(va_list ap, t_srt *lst);
wchar_t		        *ft_accurwchar(wchar_t *str, t_srt *lst);
char	            *ft_print_wchar_str(va_list ap, t_srt *lst);
wchar_t	            *ft_wchar_width(wchar_t *str, t_srt *lst);
int		            ft_strlen_wchar(wchar_t *str);
char	            *ft_cest_str(va_list ap, t_srt *lst);
void		        ft_print_wchar(wchar_t c, char *str, int *i, int *len);
int	    	        ft_cast_char(va_list ap, t_srt *lst);
int             	ft_len_wchar(wchar_t *str);
wchar_t		        *ft_wstrdup(wchar_t *str);
char                *ft_apostroph(char *str, t_srt *lst);
void                ft_argn(int len, va_list ap, t_srt *lst);
long double		    rang_e(long double nb, int *i);
char	            *ft_getpow(int i);
char                *ft_str_g(va_list ap, t_srt *lst);
int                 ft_printformat(const char *str, int *i, t_srt *lst, va_list ap);
void                ft_width_or_dolar(const char *str, int *i, t_srt *lst);
char 				*ft_plus2(char *str, t_srt *lst);
char 				*ft_strcpychar(char *s1, char *s2, int j, char c);
char 				*ft_str_dable_a2(long double nb, int len, t_srt *lst, int i);
void 				ft_ppp2(char *c, char *b);
char 				*ft_getstr_a2(long double nb, t_srt *lst);
char 				*ft_strs2(char *s, int *i, int nb);
char				*ft_pow_a2(int pow);
char 				ft_char2(int a);
char 				*ft_str_zero2(long double nb, t_srt *lst, char *s);
char 				*ft_okrug_a2(char *str);

#endif
