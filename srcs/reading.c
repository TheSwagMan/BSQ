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
/* M: 2017/08/05 13:43 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#include "reading.h"

t_linked_data	*get_input_as_bit(int fd)
{
	t_linked_data	*result;
	int				l;
	char			buffer[BUFSIZ];

	result = malloc(sizeof(*result));
	while ((l = read(fd, buffer, BUFSIZ)))
	{
		
	}
	return (result);
}
