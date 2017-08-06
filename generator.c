/* ************************************************************************** */
/*                                                  ,---.                     */
/* generator.c                                    ,.'-.   \                   */
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
/* C: 2017/08/06 18:27 by Thomas POTIER          `-.       /\  | `. ( ,\  \   */
/* M: 2017/08/06 18:46 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

struct timeval	t;

int		main(int ac, char **av)
{
	int		w;
	int		h;
	char	*str;
	int		j;

	if (ac == 7)
	{
		h = atoi(av[1]);
		w = atoi(av[2]);
		if (!(str = malloc((w + 1) * sizeof(*str))))
			return (-1);
		gettimeofday(&t, NULL);
		srand(t.tv_usec);
		printf("%i%c%c%c\n", h, *(av[3]),*(av[4]),*(av[5]));
		while (h-- > 0)
		{
			j = w;
			str[j] = 0;
			while (j-- > 0)
			{
				if (rand() % 1000 > atoi(av[6]))
					str[j] = *(av[3]);
				else
					str[j] = *(av[4]);
			}
			printf("%s\n", str);
		}
	}
	return (0);
}
