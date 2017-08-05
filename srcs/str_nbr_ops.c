/* ************************************************************************** */
/*                                                  ,---.                     */
/* str_nbr_ops.c                                  ,.'-.   \                   */
/*                                               ( ( ,'"""""-.                */
/* Thomas POTIER <thomas.potier@outlook.com>     `,X          `.              */
/*                                               /` `           `._           */
/*                                              (            ,   ,_\          */
/*                                              |          ,---.,'o `.        */
/*                                              |         / o   \     )       */
/*                                               \ ,.    (      .____,        */
/*                                                  \|     ____,'     \       */
/*                                              '`'\  \        _,____,'       */
/*                                              \  ,--      ,-'     \         */
/*                                                ( C     ,'         \        */
/*                                                 `--'  .'           |       */
/*                                                   |   |         .O |       */
/*                                                  __|            ,-'_       */
/*                                                / `L     `._  _,'  ' `.     */
/*                                               /    `--.._  `',.   _\  `    */
/* C: 2017/08/05 16:37 by Thomas POTIER          `-.       /\  | `. ( ,\  \   */
/* M: 2017/08/05 18:59 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#include "str_nbr_ops.h"

#include <stdio.h>

int		m_atoi_base(char *str, int base)
{
	int	sign;
	int	res;

	res = 0;
	while (*str == '\t' || *str == '\n' || *str == ' ' || *str == '\v')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (m_strindex(BASE_CHARS, *str) >= 0)
		res = (res * base) + m_strindex(BASE_CHARS, *(str++));
	return (res * sign);
}

char	*m_itoa_base(int nbr, int base)
{
	char			*res;
	int				l;
	unsigned int	t;
	int				n;

	n = 0;
	t = nbr;
	if (nbr < 0 && base == 10)
		n = 1;
	if (n)
		t = -nbr;
	l = nbrlen_base(t, (unsigned int)base);
	res = malloc((l + n + 1) * sizeof(*res));
	res[l + n] = 0;
	while (l >= n)
	{
		res[l--] = BASE_CHARS[t % base];
		t /= base;
	}
	if (n)
		res[0] = '-';
	return (res);
}

int		nbrlen_base(unsigned int nbr, unsigned int base)
{
	int	l;

	l = 0;
	while (nbr >= base)
	{
		nbr /= base;
		l++;
	}
	return (l);
}
