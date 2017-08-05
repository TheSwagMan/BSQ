/* ************************************************************************** */
/*                                                  ,---.                     */
/* str.c                                          ,.'-.   \                   */
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
/* C: 2017/08/05 00:01 by Thomas POTIER          `-.       /\  | `. ( ,\  \   */
/* M: 2017/08/05 17:44 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#include "str.h"

int		m_strlen(char *str)
{
	return (*str ? m_strlen(str + 1) + 1 : 0);
}

char	*m_strdup(char *str)
{
	char	*res;
	int		i;

	res = malloc((m_strlen(str) + 1) * sizeof(*res));
	for (i = 0; *str; i++)
		res[i] = *(str++);
	res[i] = '\0';
	return (res);
}

int		m_strindex(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
