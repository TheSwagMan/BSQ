/* ************************************************************************** */
/*                                                  ,---.                     */
/* linked_data.c                                  ,.'-.   \                   */
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
/* C: 2017/08/07 22:10 by Thomas POTIER          `-.       /\  | `. ( ,\  \   */
/* M: 2017/08/07 22:16 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#include "linked_data.h"

t_linked_data	*lida_create_node(char *data, int length)
{
	t_linked_data	*list;

	if (!(list = malloc(sizeof(*list))))
		exit(ERROR_MALLOC);
	list->part = data;
	list->length = length;
	list->next = NULL;
	return (list);
}

void	lida_push_back(t_linked_data **begin, char *data, int length)
{
	t_linked_data	*list;

	list = *begin;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = lida_create_node(data, length);

	}
	else
		*begin = lida_create_node(data, length);
}

