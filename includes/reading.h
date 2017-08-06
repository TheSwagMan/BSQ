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
/* M: 2017/08/06 19:46 by Thomas POTIER         _/  `-._  /  \ |--'  (     \  */
/*                                             '  `-.   `'    \/\`.   `.    ) */
/* CustomHeader ! v1.0                               \  -hrr-    \ `.  |    | */
/* ************************************************************************** */

#ifndef READING_H
# define READING_H

# include <stdlib.h>
# include "io.h"
# include "linked_data.h"
# include "str_nbr_ops.h"
# include "bsq.h"


t_map_input	*get_input_as_bit(int fd);
int			get_map_spec(t_reading_buff *buf, t_map_input *map);
int			get_map(t_reading_buff *buf, t_map_input *map);

#endif
