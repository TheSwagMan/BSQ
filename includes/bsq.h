/* ************************************************************************** */
/*                                                  ,---.                     */
/* bsq.h                                          ,.'-.   \                   */
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
/* C: 2017/08/05 15:38 by Thomas POTIER          `-.       /\  | `. ( ,\  \   */
/* M: 2017/08/07 15:58 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "io.h"
# include "linked_data.h"
# include "errors.h"

typedef struct	s_map_spec
{
	int		width;
	int		height;
	char	empty;
	char	obstacle;
	char	fill;
}				t_map_spec;

typedef struct	s_map_input
{
	t_map_spec		*specs;
	t_linked_data	*data;
}				t_map_input;

#endif
