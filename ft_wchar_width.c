#include "ft_printf.h"

wchar_t *ft_strcpywchar(wchar_t *s1, wchar_t *s2, char c, int j)
{
	int i;

	i = ft_strlen_wchar(s2);
	while (i >= 0)
	{
		s1[j] = s2[i];
		i--;
		j--;
	}
	while (j >= 0)
	{
		s1[j] = c;
		j--;
	}
	//free(s2);
	return (s1);
}

wchar_t *ft_strcpycharwchar(wchar_t *s1, wchar_t *s2, int j)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < j)
	{
		s1[i] = ' ';
		i++;
	}
	//free(s2);
	return (s1);
}

wchar_t *ft_wchar_width(wchar_t *str, t_srt *lst)
{
	wchar_t *src;

	if (lst->width != -1)
	{
		if (ft_strlen_wchar(str) < lst->width)
		{
			src = (wchar_t *) malloc(sizeof(wchar_t) * (lst->width + 1));
			if (lst->zero_or_minus == '1')
				return (ft_strcpywchar(src, str, '0', lst->width));
			else if (lst->zero_or_minus == '-')
				return (ft_strcpycharwchar(src, str, lst->width));
			else if (lst->space == ' ')
				return (ft_strcpywchar(src, str, ' ', lst->width));
			return (ft_strcpywchar(src, str, ' ', lst->width));
		}
		else
			return (str);
	}
	return (str);
}