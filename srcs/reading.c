/* ************************************************************************** */
/*                                                  ,---.                     */
/* reading.c                                      ,.'-.   \                   */
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
/* C: 2017/08/04 23:37 by Thomas POTIER          `-.       /\  | `. ( ,\  \   */
/* M: 2017/08/05 16:14 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#include "reading.h"

t_linked_data	*get_input_as_bit(int fd)
{
	t_map_spec		ms;
	t_linked_data	*result;
	int				l;
	char			readbuf[BUFSIZ];
	char			*processbuf;

	ms = *get_map_spec(&fd, (char **)&readbuf, &l);
	result = malloc(sizeof(*result));
	while ((l = read(fd, readbuf, BUFSIZ)))
	{
		processbuf = malloc(l / 8 + 1);
		while (l > 0)
			l--;
	}
	(void)ms;
	(void)processbuf;
	return (result);
}

t_map_spec		*get_map_spec(int *fd, char **readbuf, int *l)
{
	int			i;
	t_map_spec	*ms;

	ms = malloc(sizeof(*ms));
	i = 0;
	*l = read(*fd, *readbuf, BUFSIZ);
	(void)i;
	return (ms);
}
