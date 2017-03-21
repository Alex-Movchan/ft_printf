#include "ft_printf.h"

wchar_t *ft_strncpywchar(wchar_t *str, wchar_t *src, int len)
{
	wchar_t *d;
	wchar_t *s;

	d = str;
	s = src;
	while (len > 0 && *s)
	{
		*d++ = *s++;
		len--;
	}
	while (len > 0)
	{
		len--;
		*d++ = '\0';
	}
	return (str);
}

wchar_t *ft_strndupwchar(wchar_t *str, int len)
{
	wchar_t *src;

	src = (wchar_t *) malloc(sizeof(wchar_t) * (len + 1));
	src = ft_strncpywchar(src, str, len);
	free(str);
	return (src);
}

wchar_t *ft_accurwchar(wchar_t *str, t_srt *lst)
{
	if (lst->accur != -1)
		return (ft_strndupwchar(str, lst->accur));
	else
		return (str);
}

wchar_t *ft_wstrdup(wchar_t *str)
{
	wchar_t *src;
	int i;

	i = 0;
	src = (wchar_t *) malloc(sizeof(wchar_t) * (ft_strlen_wchar(str) + 1));
	while (str[i])
	{
		src[i] = str[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}