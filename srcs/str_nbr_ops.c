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
/* M: 2017/08/05 17:04 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#include "str_nbr_ops.h"

int		m_atoi(char *str)
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
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str + 0x30);
	return (res * sign);
}

char	*m_itoa(int nbr)
{
	char	*res;

	res = malloc(nbr * sizeof(*res));
	return (res);
}
