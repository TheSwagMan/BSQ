/* ************************************************************************** */
/*                                                  ,---.                     */
/* linked_data.h                                  ,.'-.   \                   */
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
/* C: 2017/08/05 12:51 by Thomas POTIER          `-.       /\  | `. ( ,\  \   */
/* M: 2017/08/07 22:16 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#ifndef LINKED_DATA_H
# define LINKED_DATA_H

# include "errors.h"

typedef struct	s_linked_data
{
	char					*part;
	int						length;
	struct s_linked_data	*next;
}				t_linked_data;

t_linked_data	*lida_create_node(char *data, int length);
void			lida_push_back(t_linked_data **begin, char *data, int length);


#endif
