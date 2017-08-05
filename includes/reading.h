/* ************************************************************************** */
/*                                                  ,---.                     */
/* reading.h                                      ,.'-.   \                   */
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
/* C: 2017/08/05 01:45 by Thomas POTIER          `-.       /\  | `. ( ,\  \   */
/* M: 2017/08/05 16:06 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#ifndef READING_H
# define READING_H

# include <stdlib.h>
# include "io.h"
# include "linked_data.h"
# include "bsq.h"

t_linked_data	*get_input_as_bit(int fd);
t_map_spec		*get_map_spec(int *fd, char **readbuf, int *l);

#endif
